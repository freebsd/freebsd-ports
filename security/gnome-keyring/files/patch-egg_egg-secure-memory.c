--- egg/egg-secure-memory.c.orig	Wed Sep 26 10:28:35 2012
+++ egg/egg-secure-memory.c	Sat Oct 27 14:46:28 2012
@@ -22,8 +22,8 @@
 */
 
 /*
- * IMPORTANT: This is pure vanila standard C, no glib. We need this 
- * because certain consumers of this protocol need to be built 
+ * IMPORTANT: This is pure vanila standard C, no glib. We need this
+ * because certain consumers of this protocol need to be built
  * without linking in any special libraries. ie: the PKCS#11 module.
  */
 
@@ -48,8 +48,8 @@
 
 #define DEBUG_SECURE_MEMORY 0
 
-#if DEBUG_SECURE_MEMORY 
-#define DEBUG_ALLOC(msg, n) 	fprintf(stderr, "%s %lu bytes\n", msg, n); 
+#if DEBUG_SECURE_MEMORY
+#define DEBUG_ALLOC(msg, n) 	fprintf(stderr, "%s %lu bytes\n", msg, n);
 #else
 #define DEBUG_ALLOC(msg, n)
 #endif
@@ -59,8 +59,8 @@
 /* Use our own assert to guarantee no glib allocations */
 #ifndef ASSERT
 #ifdef G_DISABLE_ASSERT
-#define ASSERT(x) 
-#else 
+#define ASSERT(x)
+#else
 #define ASSERT(x) assert(x)
 #endif
 #endif
@@ -74,18 +74,18 @@
 static int show_warning = 1;
 int egg_secure_warnings = 1;
 
-/* 
- * We allocate all memory in units of sizeof(void*). This 
+/*
+ * We allocate all memory in units of sizeof(void*). This
  * is our definition of 'word'.
  */
 typedef void* word_t;
 
-/* The amount of extra words we can allocate */ 
+/* The amount of extra words we can allocate */
 #define WASTE   4
 
-/* 
- * Track allocated memory or a free block. This structure is not stored 
- * in the secure memory area. It is allocated from a pool of other 
+/*
+ * Track allocated memory or a free block. This structure is not stored
+ * in the secure memory area. It is allocated from a pool of other
  * memory. See meta_pool_xxx ().
  */
 typedef struct _Cell {
@@ -97,7 +97,7 @@ typedef struct _Cell {
 	struct _Cell *prev;     /* Previous in memory ring */
 } Cell;
 
-/* 
+/*
  * A block of secure memory. This structure is the header in that block.
  */
 typedef struct _Block {
@@ -130,20 +130,20 @@ unused_pop (void **stack)
 	ptr = *stack;
 	*stack = *(void**)ptr;
 	return ptr;
-	
+
 }
 
 static inline void*
 unused_peek (void **stack)
 {
 	ASSERT (stack);
-	return *stack; 
+	return *stack;
 }
 
 /* -----------------------------------------------------------------------------
  * POOL META DATA ALLOCATION
- * 
- * A pool for memory meta data. We allocate fixed size blocks. There are actually 
+ *
+ * A pool for memory meta data. We allocate fixed size blocks. There are actually
  * two different structures stored in this pool: Cell and Block. Cell is allocated
  * way more often, and is bigger so we just allocate that size for both.
  */
@@ -185,7 +185,7 @@ pool_alloc (void)
 		if (unused_peek (&pool->unused))
 			break;
 	}
-	
+
 	/* Create a new pool */
 	if (pool == NULL) {
 		len = getpagesize () * 2;
@@ -205,7 +205,7 @@ pool_alloc (void)
 		pool->n_items = (len - sizeof (Pool)) / sizeof (Item);
 		for (i = 0; i < pool->n_items; ++i)
 			unused_push (&pool->unused, pool->items + i);
-		
+
 #ifdef WITH_VALGRIND
 		VALGRIND_CREATE_MEMPOOL(pool, 0, 0);
 #endif
@@ -227,9 +227,9 @@ pool_free (void* item)
 {
 	Pool *pool, **at;
 	char *ptr, *beg, *end;
-	
+
 	ptr = item;
-	
+
 	/* Find which block this one belongs to */
 	for (at = (Pool **)&EGG_SECURE_GLOBALS.pool_data, pool = *at;
 	     pool != NULL; at = &pool->next, pool = *at) {
@@ -275,17 +275,17 @@ pool_valid (void* item)
 {
 	Pool *pool;
 	char *ptr, *beg, *end;
-	
+
 	ptr = item;
-	
+
 	/* Find which block this one belongs to */
 	for (pool = EGG_SECURE_GLOBALS.pool_data; pool; pool = pool->next) {
 		beg = (char*)pool->items;
 		end = (char*)pool + pool->length - sizeof (Item);
-		if (ptr >= beg && ptr <= end) 
+		if (ptr >= beg && ptr <= end)
 			return (pool->used && (ptr - beg) % sizeof (Item) == 0);
 	}
-	
+
 	return 0;
 }
 
@@ -293,9 +293,9 @@ pool_valid (void* item)
 
 /* -----------------------------------------------------------------------------
  * SEC ALLOCATION
- * 
+ *
  * Each memory cell begins and ends with a pointer to its metadata. These are also
- * used as guards or red zones. Since they're treated as redzones by valgrind we 
+ * used as guards or red zones. Since they're treated as redzones by valgrind we
  * have to jump through a few hoops before reading and/or writing them.
  */
 
@@ -315,11 +315,11 @@ sec_write_guards (Cell *cell)
 
 	((void**)cell->words)[0] = (void*)cell;
 	((void**)cell->words)[cell->n_words - 1] = (void*)cell;
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_NOACCESS (cell->words, sizeof (word_t));
 	VALGRIND_MAKE_MEM_NOACCESS (cell->words + cell->n_words - 1, sizeof (word_t));
-#endif	
+#endif
 }
 
 static inline void
@@ -327,16 +327,16 @@ sec_check_guards (Cell *cell)
 {
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (cell->words, sizeof (word_t));
-	VALGRIND_MAKE_MEM_DEFINED (cell->words + cell->n_words - 1, sizeof (word_t)); 
-#endif	
-	
+	VALGRIND_MAKE_MEM_DEFINED (cell->words + cell->n_words - 1, sizeof (word_t));
+#endif
+
 	ASSERT(((void**)cell->words)[0] == (void*)cell);
 	ASSERT(((void**)cell->words)[cell->n_words - 1] == (void*)cell);
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_NOACCESS (cell->words, sizeof (word_t));
 	VALGRIND_MAKE_MEM_NOACCESS (cell->words + cell->n_words - 1, sizeof (word_t));
-#endif	
+#endif
 }
 
 static void
@@ -347,9 +347,9 @@ sec_insert_cell_ring (Cell **ring, Cell *cell)
 	ASSERT (cell != *ring);
 	ASSERT (cell->next == NULL);
 	ASSERT (cell->prev == NULL);
-	
-	/* Insert back into the mix of available memory */ 
-	if (*ring) { 
+
+	/* Insert back into the mix of available memory */
+	if (*ring) {
 		cell->next = (*ring)->next;
 		cell->prev = *ring;
 		cell->next->prev = cell;
@@ -358,7 +358,7 @@ sec_insert_cell_ring (Cell **ring, Cell *cell)
 		cell->next = cell;
 		cell->prev = cell;
 	}
-	
+
 	*ring = cell;
 	ASSERT (cell->next->prev == cell);
 	ASSERT (cell->prev->next == cell);
@@ -391,7 +391,7 @@ sec_remove_cell_ring (Cell **ring, Cell *cell)
 	cell->next->prev = cell->prev;
 	cell->prev->next = cell->next;
 	cell->next = cell->prev = NULL;
-	
+
 	ASSERT (*ring != cell);
 }
 
@@ -440,10 +440,10 @@ static Cell*
 sec_neighbor_before (Block *block, Cell *cell)
 {
 	word_t *word;
-	
+
 	ASSERT (cell);
 	ASSERT (block);
-	
+
 	word = cell->words - 1;
 	if (!sec_is_valid_word (block, word))
 		return NULL;
@@ -451,7 +451,7 @@ sec_neighbor_before (Block *block, Cell *cell)
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (word, sizeof (word_t));
 #endif
-	
+
 	cell = *word;
 	sec_check_guards (cell);
 
@@ -462,14 +462,14 @@ sec_neighbor_before (Block *block, Cell *cell)
 	return cell;
 }
 
-static Cell* 
+static Cell*
 sec_neighbor_after (Block *block, Cell *cell)
 {
 	word_t *word;
-	
+
 	ASSERT (cell);
 	ASSERT (block);
-	
+
 	word = cell->words + cell->n_words;
 	if (!sec_is_valid_word (block, word))
 		return NULL;
@@ -480,7 +480,7 @@ sec_neighbor_after (Block *block, Cell *cell)
 
 	cell = *word;
 	sec_check_guards (cell);
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_NOACCESS (word, sizeof (word_t));
 #endif
@@ -496,7 +496,7 @@ sec_alloc (Block *block,
 	Cell *cell, *other;
 	size_t n_words;
 	void *memory;
-	
+
 	ASSERT (block);
 	ASSERT (length);
 	ASSERT (tag);
@@ -504,16 +504,16 @@ sec_alloc (Block *block,
 	if (!block->unused_cells)
 		return NULL;
 
-	/* 
-	 * Each memory allocation is aligned to a pointer size, and 
+	/*
+	 * Each memory allocation is aligned to a pointer size, and
 	 * then, sandwidched between two pointers to its meta data.
 	 * These pointers also act as guards.
 	 *
-	 * We allocate memory in units of sizeof (void*) 
+	 * We allocate memory in units of sizeof (void*)
 	 */
-	
+
 	n_words = sec_size_to_words (length) + 2;
-	
+
 	/* Look for a cell of at least our required size */
 	cell = block->unused_cells;
 	while (cell->n_words < n_words) {
@@ -523,7 +523,7 @@ sec_alloc (Block *block,
 			break;
 		}
 	}
-	
+
 	if (!cell)
 		return NULL;
 
@@ -532,7 +532,7 @@ sec_alloc (Block *block,
 	ASSERT (cell->prev);
 	ASSERT (cell->words);
 	sec_check_guards (cell);
-	
+
 	/* Steal from the cell if it's too long */
 	if (cell->n_words > n_words + WASTE) {
 		other = pool_alloc ();
@@ -542,13 +542,13 @@ sec_alloc (Block *block,
 		other->words = cell->words;
 		cell->n_words -= n_words;
 		cell->words += n_words;
-		
+
 		sec_write_guards (other);
 		sec_write_guards (cell);
-		
+
 		cell = other;
 	}
-	
+
 	if (cell->next)
 		sec_remove_cell_ring (&block->unused_cells, cell);
 
@@ -557,11 +557,11 @@ sec_alloc (Block *block,
 	cell->requested = length;
 	sec_insert_cell_ring (&block->used_cells, cell);
 	memory = sec_cell_to_memory (cell);
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_UNDEFINED (memory, length);
 #endif
-	
+
 	return memset (memory, 0, length);
 }
 
@@ -570,13 +570,13 @@ sec_free (Block *block, void *memory)
 {
 	Cell *cell, *other;
 	word_t *word;
-	
+
 	ASSERT (block);
 	ASSERT (memory);
-	
+
 	word = memory;
 	--word;
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (word, sizeof (word_t));
 #endif
@@ -600,39 +600,39 @@ sec_free (Block *block, void *memory)
 	/* Remove from the used cell ring */
 	sec_remove_cell_ring (&block->used_cells, cell);
 
-        /* Find previous unallocated neighbor, and merge if possible */
-        other = sec_neighbor_before (block, cell);
-        if (other && other->requested == 0) {
-        	ASSERT (other->tag == NULL);
-        	ASSERT (other->next && other->prev);
-        	other->n_words += cell->n_words;
-        	sec_write_guards (other);
-        	pool_free (cell);
-        	cell = other;
-        } 
-        
-        /* Find next unallocated neighbor, and merge if possible */
-        other = sec_neighbor_after (block, cell);
-        if (other && other->requested == 0) {
-        	ASSERT (other->tag == NULL);
-        	ASSERT (other->next && other->prev);
-        	other->n_words += cell->n_words;
-        	other->words = cell->words;
-        	if (cell->next)
-        		sec_remove_cell_ring (&block->unused_cells, cell);
-        	sec_write_guards (other);
-        	pool_free (cell);
-        	cell = other;
-        }
+	/* Find previous unallocated neighbor, and merge if possible */
+	other = sec_neighbor_before (block, cell);
+	if (other && other->requested == 0) {
+		ASSERT (other->tag == NULL);
+		ASSERT (other->next && other->prev);
+		other->n_words += cell->n_words;
+		sec_write_guards (other);
+		pool_free (cell);
+		cell = other;
+	}
 
-        /* Add to the unused list if not already there */
-        if (!cell->next)
-        	sec_insert_cell_ring (&block->unused_cells, cell);
+	/* Find next unallocated neighbor, and merge if possible */
+	other = sec_neighbor_after (block, cell);
+	if (other && other->requested == 0) {
+		ASSERT (other->tag == NULL);
+		ASSERT (other->next && other->prev);
+		other->n_words += cell->n_words;
+		other->words = cell->words;
+		if (cell->next)
+			sec_remove_cell_ring (&block->unused_cells, cell);
+		sec_write_guards (other);
+		pool_free (cell);
+		cell = other;
+	}
 
-        cell->tag = NULL;
-        cell->requested = 0;
-        --block->n_used;
-        return NULL;
+	/* Add to the unused list if not already there */
+	if (!cell->next)
+		sec_insert_cell_ring (&block->unused_cells, cell);
+
+	cell->tag = NULL;
+	cell->requested = 0;
+	--block->n_used;
+	return NULL;
 }
 
 static void
@@ -683,7 +683,7 @@ sec_realloc (Block *block,
 	/* Dig out where the meta should be */
 	word = memory;
 	--word;
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (word, sizeof (word_t));
 #endif
@@ -691,7 +691,7 @@ sec_realloc (Block *block,
 	ASSERT (sec_is_valid_word (block, word));
 	ASSERT (pool_valid (*word));
 	cell = *word;
-	
+
 	/* Validate that it's actually for real */
 	sec_check_guards (cell);
 	ASSERT (cell->requested > 0);
@@ -710,17 +710,17 @@ sec_realloc (Block *block,
 		cell->requested = length;
 		alloc = sec_cell_to_memory (cell);
 
-		/* 
+		/*
 		 * Even though we may be reusing the same cell, that doesn't
 		 * mean that the allocation is shrinking. It could have shrunk
-		 * and is now expanding back some. 
-		 */ 
+		 * and is now expanding back some.
+		 */
 		if (length < valid)
 			sec_clear_undefined (alloc, length, valid);
 
 		return alloc;
 	}
-	
+
 	/* Need braaaaaiiiiiinsss... */
 	while (cell->n_words < n_words) {
 
@@ -728,7 +728,7 @@ sec_realloc (Block *block,
 		other = sec_neighbor_after (block, cell);
 		if (!other || other->requested != 0)
 			break;
-		
+
 		/* Eat the whole neighbor if not too big */
 		if (n_words - cell->n_words + WASTE >= other->n_words) {
 			cell->n_words += other->n_words;
@@ -745,7 +745,7 @@ sec_realloc (Block *block,
 			sec_write_guards (cell);
 		}
 	}
-	
+
 	if (cell->n_words >= n_words) {
 		cell->requested = length;
 		cell->tag = tag;
@@ -760,7 +760,7 @@ sec_realloc (Block *block,
 		memcpy_with_vbits (alloc, memory, valid);
 		sec_free (block, memory);
 	}
-	
+
 	return alloc;
 }
 
@@ -770,7 +770,7 @@ sec_allocated (Block *block, void *memory)
 {
 	Cell *cell;
 	word_t *word;
-	
+
 	ASSERT (block);
 	ASSERT (memory);
 
@@ -780,12 +780,12 @@ sec_allocated (Block *block, void *memory)
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (word, sizeof (word_t));
 #endif
-	
+
 	/* Lookup the meta for this memory block (using guard pointer) */
 	ASSERT (sec_is_valid_word (block, word));
 	ASSERT (pool_valid (*word));
 	cell = *word;
-	
+
 	sec_check_guards (cell);
 	ASSERT (cell->requested > 0);
 	ASSERT (cell->tag != NULL);
@@ -817,10 +817,10 @@ sec_validate (Block *block)
 		ASSERT (sec_is_valid_word (block, word));
 		ASSERT (pool_valid (*word));
 		cell = *word;
-	
+
 		/* Validate that it's actually for real */
 		sec_check_guards (cell);
-	
+
 		/* Is it an allocated block? */
 		if (cell->requested > 0) {
 			ASSERT (cell->tag != NULL);
@@ -829,7 +829,7 @@ sec_validate (Block *block)
 			ASSERT (cell->next->prev == cell);
 			ASSERT (cell->prev->next == cell);
 			ASSERT (cell->requested <= (cell->n_words - 2) * sizeof (word_t));
-		
+
 		/* An unused block */
 		} else {
 			ASSERT (cell->tag == NULL);
@@ -838,7 +838,7 @@ sec_validate (Block *block)
 			ASSERT (cell->next->prev == cell);
 			ASSERT (cell->prev->next == cell);
 		}
-		
+
 		word += cell->n_words;
 		if (word == last)
 			break;
@@ -855,7 +855,7 @@ sec_acquire_pages (size_t *sz,
 {
 	void *pages;
 	unsigned long pgsize;
-	
+
 	ASSERT (sz);
 	ASSERT (*sz);
 	ASSERT (during_tag);
@@ -863,7 +863,7 @@ sec_acquire_pages (size_t *sz,
 	/* Make sure sz is a multiple of the page size */
 	pgsize = getpagesize ();
 	*sz = (*sz + pgsize -1) & ~(pgsize - 1);
-	
+
 #if defined(HAVE_MLOCK)
 	pages = mmap (0, *sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
 	if (pages == MAP_FAILED) {
@@ -873,7 +873,7 @@ sec_acquire_pages (size_t *sz,
 		show_warning = 0;
 		return NULL;
 	}
-	
+
 	if (mlock (pages, *sz) < 0) {
 		if (show_warning && egg_secure_warnings && errno != EPERM) {
 			fprintf (stderr, "couldn't lock %lu bytes of memory (%s): %s\n",
@@ -883,12 +883,12 @@ sec_acquire_pages (size_t *sz,
 		munmap (pages, *sz);
 		return NULL;
 	}
-	
+
 	DEBUG_ALLOC ("gkr-secure-memory: new block ", *sz);
-	
+
 	show_warning = 1;
 	return pages;
-	
+
 #else
 	if (show_warning && egg_secure_warnings)
 		fprintf (stderr, "your system does not support private memory");
@@ -898,21 +898,21 @@ sec_acquire_pages (size_t *sz,
 
 }
 
-static void 
+static void
 sec_release_pages (void *pages, size_t sz)
 {
 	ASSERT (pages);
 	ASSERT (sz % getpagesize () == 0);
-	
+
 #if defined(HAVE_MLOCK)
 	if (munlock (pages, sz) < 0 && egg_secure_warnings)
 		fprintf (stderr, "couldn't unlock private memory: %s\n", strerror (errno));
-		
+
 	if (munmap (pages, sz) < 0 && egg_secure_warnings)
 		fprintf (stderr, "couldn't unmap private anonymous memory: %s\n", strerror (errno));
-		
+
 	DEBUG_ALLOC ("gkr-secure-memory: freed block ", sz);
-	
+
 #else
 	ASSERT (FALSE);
 #endif
@@ -924,7 +924,7 @@ sec_release_pages (void *pages, size_t sz)
 
 static Block *all_blocks = NULL;
 
-static Block* 
+static Block*
 sec_block_create (size_t size,
                   const char *during_tag)
 {
@@ -950,7 +950,7 @@ sec_block_create (size_t size,
 	/* The size above is a minimum, we're free to go bigger */
 	if (size < DEFAULT_BLOCK_SIZE)
 		size = DEFAULT_BLOCK_SIZE;
-		
+
 	block->words = sec_acquire_pages (&size, during_tag);
 	block->n_words = size / sizeof (word_t);
 	if (!block->words) {
@@ -958,11 +958,11 @@ sec_block_create (size_t size,
 		pool_free (cell);
 		return NULL;
 	}
-	
+
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_DEFINED (block->words, size);
 #endif
-	
+
 	/* The first cell to allocate from */
 	cell->words = block->words;
 	cell->n_words = block->n_words;
@@ -972,7 +972,7 @@ sec_block_create (size_t size,
 
 	block->next = all_blocks;
 	all_blocks = block;
-	
+
 	return block;
 }
 
@@ -985,7 +985,7 @@ sec_block_destroy (Block *block)
 	ASSERT (block);
 	ASSERT (block->words);
 	ASSERT (block->n_used == 0);
-	
+
 	/* Remove from the list */
 	for (at = &all_blocks, bl = *at; bl; at = &bl->next, bl = *at) {
 		if (bl == block) {
@@ -993,7 +993,7 @@ sec_block_destroy (Block *block)
 			break;
 		}
 	}
-	
+
 	/* Must have been found */
 	ASSERT (bl == block);
 	ASSERT (block->used_cells == NULL);
@@ -1004,7 +1004,7 @@ sec_block_destroy (Block *block)
 		sec_remove_cell_ring (&block->unused_cells, cell);
 		pool_free (cell);
 	}
-	
+
 	/* Release all pages of secure memory */
 	sec_release_pages (block->words, block->n_words * sizeof (word_t));
 
@@ -1028,35 +1028,35 @@ egg_secure_alloc_full (const char *tag,
 
 	if (length > 0xFFFFFFFF / 2) {
 		if (egg_secure_warnings)
-			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n", 
-			         (unsigned long)length);   
+			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n",
+			         (unsigned long)length);
 		return NULL;
 	}
 
 	/* Can't allocate zero bytes */
 	if (length == 0)
 		return NULL;
-	
+
 	DO_LOCK ();
-	
+
 		for (block = all_blocks; block; block = block->next) {
 			memory = sec_alloc (block, tag, length);
 			if (memory)
-				break;	
+				break;
 		}
-	
+
 		/* None of the current blocks have space, allocate new */
 		if (!memory) {
 			block = sec_block_create (length, tag);
 			if (block)
 				memory = sec_alloc (block, tag, length);
 		}
-		
+
 #ifdef WITH_VALGRIND
 		if (memory != NULL)
 			VALGRIND_MALLOCLIKE_BLOCK (memory, length, sizeof (void*), 1);
 #endif
-	
+
 	DO_UNLOCK ();
 
 	if (!memory && (flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback != NULL) {
@@ -1064,10 +1064,10 @@ egg_secure_alloc_full (const char *tag,
 		if (memory) /* Our returned memory is always zeroed */
 			memset (memory, 0, length);
 	}
-	
+
 	if (!memory)
 		errno = ENOMEM;
-	
+
 	return memory;
 }
 
@@ -1087,20 +1087,20 @@ egg_secure_realloc_full (const char *tag,
 
 	if (length > 0xFFFFFFFF / 2) {
 		if (egg_secure_warnings)
-			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n", 
+			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n",
 			         (unsigned long)length);
 		return NULL;
 	}
-	
+
 	if (memory == NULL)
 		return egg_secure_alloc_full (tag, length, flags);
 	if (!length) {
 		egg_secure_free_full (memory, flags);
 		return NULL;
 	}
-	
+
 	DO_LOCK ();
-	
+
 		/* Find out where it belongs to */
 		for (block = all_blocks; block; block = block->next) {
 			if (sec_is_valid_word (block, memory)) {
@@ -1115,10 +1115,10 @@ egg_secure_realloc_full (const char *tag,
 
 #ifdef WITH_VALGRIND
 				/* Now tell valgrind about either the new block or old one */
-				VALGRIND_MALLOCLIKE_BLOCK (alloc ? alloc : memory, 
-				                           alloc ? length : previous, 
+				VALGRIND_MALLOCLIKE_BLOCK (alloc ? alloc : memory,
+				                           alloc ? length : previous,
 				                           sizeof (word_t), 1);
-#endif					
+#endif
 				break;
 			}
 		}
@@ -1129,13 +1129,13 @@ egg_secure_realloc_full (const char *tag,
 
 		if (block && block->n_used == 0)
 			sec_block_destroy (block);
-		
-	DO_UNLOCK ();		
-	
+
+	DO_UNLOCK ();
+
 	if (!block) {
 		if ((flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback) {
-			/* 
-			 * In this case we can't zero the returned memory, 
+			/*
+			 * In this case we can't zero the returned memory,
 			 * because we don't know what the block size was.
 			 */
 			return EGG_SECURE_GLOBALS.fallback (memory, length);
@@ -1155,7 +1155,7 @@ egg_secure_realloc_full (const char *tag,
 			egg_secure_free_full (memory, flags);
 		}
 	}
-	
+
 	if (!alloc)
 		errno = ENOMEM;
 
@@ -1172,12 +1172,12 @@ void
 egg_secure_free_full (void *memory, int flags)
 {
 	Block *block = NULL;
-	
+
 	if (memory == NULL)
 		return;
-	
+
 	DO_LOCK ();
-	
+
 		/* Find out where it belongs to */
 		for (block = all_blocks; block; block = block->next) {
 			if (sec_is_valid_word (block, memory))
@@ -1195,9 +1195,9 @@ egg_secure_free_full (void *memory, int flags)
 			if (block->n_used == 0)
 				sec_block_destroy (block);
 		}
-			
+
 	DO_UNLOCK ();
-	
+
 	if (!block) {
 		if ((flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback) {
 			EGG_SECURE_GLOBALS.fallback (memory, 0);
@@ -1208,36 +1208,36 @@ egg_secure_free_full (void *memory, int flags)
 			ASSERT (0 && "memory does does not belong to secure memory pool");
 		}
 	}
-} 
+}
 
-int  
+int
 egg_secure_check (const void *memory)
 {
 	Block *block = NULL;
 
 	DO_LOCK ();
-	
+
 		/* Find out where it belongs to */
 		for (block = all_blocks; block; block = block->next) {
 			if (sec_is_valid_word (block, (word_t*)memory))
 				break;
 		}
-		
+
 	DO_UNLOCK ();
-	
+
 	return block == NULL ? 0 : 1;
-} 
+}
 
 void
 egg_secure_validate (void)
 {
 	Block *block = NULL;
-	
+
 	DO_LOCK ();
-	
+
 		for (block = all_blocks; block; block = block->next)
 			sec_validate (block);
-		
+
 	DO_UNLOCK ();
 }
 
@@ -1320,20 +1320,42 @@ egg_secure_strdup_full (const char *tag,
 	if (!str)
 		return NULL;
 
-	len = strlen (str) + 1;	
+	len = strlen (str) + 1;
 	res = (char *)egg_secure_alloc_full (tag, len, options);
 	strcpy (res, str);
 	return res;
 }
 
+char *
+egg_secure_strndup_full (const char *tag,
+                         const char *str,
+                         size_t length,
+                         int options)
+{
+	size_t len;
+	char *res;
+	const char *end;
+
+	if (!str)
+		return NULL;
+
+	end = memchr (str, '\0', length);
+	if (end != NULL)
+		length = (end - str);
+	len = length + 1;
+	res = (char *)egg_secure_alloc_full (tag, len, options);
+	memcpy (res, str, len);
+	return res;
+}
+
 void
 egg_secure_clear (void *p, size_t length)
 {
 	volatile char *vp;
-	
+
 	if (p == NULL)
 		return;
-		
+
         vp = (volatile char*)p;
         while (length) {
 	        *vp = 0xAA;
@@ -1355,10 +1377,10 @@ egg_secure_strfree (char *str)
 {
 	/*
 	 * If we're using unpageable 'secure' memory, then the free call
-	 * should zero out the memory, but because on certain platforms 
+	 * should zero out the memory, but because on certain platforms
 	 * we may be using normal memory, zero it out here just in case.
 	 */
-	
+
 	egg_secure_strclear (str);
 	egg_secure_free_full (str, EGG_SECURE_USE_FALLBACK);
 }
