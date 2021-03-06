/**********************************************************************
 *
 * PROJECT:		Types library
 * FILE:		Tree.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		AA tree implementation. AA trees are a variation of an
 *				rb-tree, see http://en.wikipedia.org/wiki/AA_tree
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_TREE_H
#define __MYLLY_TREE_H

#include "stdtypes.h"

typedef struct tnode_t
{
	uint32			key;		// A unique key for this node
	uint32			level;		// Level (=height)
	struct tnode_t*	left;		// Left subtree
	struct tnode_t*	right;		// Right subtree
} tnode_t;

typedef struct tree_t
{
	tnode_t*		root;		// Root node
	tnode_t*		deleted;	// Temp recursive pointer
	tnode_t*		last;		// Temp recursive pointer
	tnode_t			null;		// A null node
	uint32			size;		// Entry count

	void (*destructor)( void* );	// A destructor function for the data
} tree_t;

__BEGIN_DECLS

MYLLY_API tree_t*			tree_create				( void (*destructor)( void* ) );
MYLLY_API void				tree_destroy			( tree_t* tree );

MYLLY_API tnode_t*			tree_find				( tree_t* tree, uint32 key );
MYLLY_API void				tree_insert				( tree_t* tree, uint32 key, tnode_t* data );
MYLLY_API void				tree_remove				( tree_t* tree, uint32 key );

__END_DECLS

#endif /* __MYLLY_TREE_H */
