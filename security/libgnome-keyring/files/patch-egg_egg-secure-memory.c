--- egg/egg-secure-memory.c.orig	Wed Jun  8 10:00:06 2011
+++ egg/egg-secure-memory.c	Sat Oct 27 14:36:16 2012
@@ -46,12 +46,6 @@
 #include <valgrind/memcheck.h>
 #endif
 
-/*
- * Use this to force all memory through malloc
- * for use with valgrind and the like
- */
-#define FORCE_FALLBACK_MEMORY 0
-
 #define DEBUG_SECURE_MEMORY 0
 
 #if DEBUG_SECURE_MEMORY
@@ -72,12 +66,12 @@
 #endif
 
 #define DO_LOCK() \
-	egg_memory_lock ();
+	EGG_SECURE_GLOBALS.lock ();
 
 #define DO_UNLOCK() \
-	egg_memory_unlock ();
+	EGG_SECURE_GLOBALS.unlock ();
 
-static int lock_warning = 1;
+static int show_warning = 1;
 int egg_secure_warnings = 1;
 
 /*
@@ -97,20 +91,22 @@ typedef void* word_t;
 typedef struct _Cell {
 	word_t *words;          /* Pointer to secure memory */
 	size_t n_words;         /* Amount of secure memory in words */
-	size_t allocated;       /* Amount actually requested by app, in bytes, 0 if unused */
-	struct _Cell *next;     /* Next in unused memory ring, or NULL if used */
-	struct _Cell *prev;     /* Previous in unused memory ring, or NULL if used */
+	size_t requested;       /* Amount actually requested by app, in bytes, 0 if unused */
+	const char *tag;        /* Tag which describes the allocation */
+	struct _Cell *next;     /* Next in memory ring */
+	struct _Cell *prev;     /* Previous in memory ring */
 } Cell;
 
 /*
  * A block of secure memory. This structure is the header in that block.
  */
 typedef struct _Block {
-	word_t *words;          /* Actual memory hangs off here */
-	size_t n_words;         /* Number of words in block */
-	size_t used;            /* Number of used allocations */
-	struct _Cell* unused;   /* Ring of unused allocations */
-	struct _Block *next;    /* Next block in list */
+	word_t *words;              /* Actual memory hangs off here */
+	size_t n_words;             /* Number of words in block */
+	size_t n_used;              /* Number of used allocations */
+	struct _Cell* used_cells;   /* Ring of used allocations */
+	struct _Cell* unused_cells; /* Ring of unused allocations */
+	struct _Block *next;        /* Next block in list */
 } Block;
 
 /* -----------------------------------------------------------------------------
@@ -167,17 +163,25 @@ typedef struct _Pool {
 	Item items[1];         /* Actual items hang off here */
 } Pool;
 
-static Pool *all_pools = NULL;
-
-static void*
+static void *
 pool_alloc (void)
 {
 	Pool *pool;
 	void *pages, *item;
 	size_t len, i;
 
+	if (!EGG_SECURE_GLOBALS.pool_version ||
+	    strcmp (EGG_SECURE_GLOBALS.pool_version, EGG_SECURE_POOL_VER_STR) != 0) {
+		if (show_warning && egg_secure_warnings)
+			fprintf (stderr, "the secure memory pool version does not match the code '%s' != '%s'\n",
+			         EGG_SECURE_GLOBALS.pool_version ? EGG_SECURE_GLOBALS.pool_version : "(null)",
+			         EGG_SECURE_POOL_VER_STR);
+		show_warning = 0;
+		return NULL;
+	}
+
 	/* A pool with an available item */
-	for (pool = all_pools; pool; pool = pool->next) {
+	for (pool = EGG_SECURE_GLOBALS.pool_data; pool; pool = pool->next) {
 		if (unused_peek (&pool->unused))
 			break;
 	}
@@ -191,8 +195,8 @@ pool_alloc (void)
 
 		/* Fill in the block header, and inlude in block list */
 		pool = pages;
-		pool->next = all_pools;
-		all_pools = pool;
+		pool->next = EGG_SECURE_GLOBALS.pool_data;
+		EGG_SECURE_GLOBALS.pool_data = pool;
 		pool->length = len;
 		pool->used = 0;
 		pool->unused = NULL;
@@ -227,7 +231,8 @@ pool_free (void* item)
 	ptr = item;
 
 	/* Find which block this one belongs to */
-	for (at = &all_pools, pool = *at; pool; at = &pool->next, pool = *at) {
+	for (at = (Pool **)&EGG_SECURE_GLOBALS.pool_data, pool = *at;
+	     pool != NULL; at = &pool->next, pool = *at) {
 		beg = (char*)pool->items;
 		end = (char*)pool + pool->length - sizeof (Item);
 		if (ptr >= beg && ptr <= end) {
@@ -263,6 +268,8 @@ pool_free (void* item)
 	unused_push (&pool->unused, item);
 }
 
+#ifndef G_DISABLE_ASSERT
+
 static int
 pool_valid (void* item)
 {
@@ -272,7 +279,7 @@ pool_valid (void* item)
 	ptr = item;
 
 	/* Find which block this one belongs to */
-	for (pool = all_pools; pool; pool = pool->next) {
+	for (pool = EGG_SECURE_GLOBALS.pool_data; pool; pool = pool->next) {
 		beg = (char*)pool->items;
 		end = (char*)pool + pool->length - sizeof (Item);
 		if (ptr >= beg && ptr <= end)
@@ -282,6 +289,8 @@ pool_valid (void* item)
 	return 0;
 }
 
+#endif /* G_DISABLE_ASSERT */
+
 /* -----------------------------------------------------------------------------
  * SEC ALLOCATION
  *
@@ -398,13 +407,34 @@ sec_is_valid_word (Block *block, word_t *word)
 	return (word >= block->words && word < block->words + block->n_words);
 }
 
-static inline void*
-sec_clear_memory (void *memory, size_t from, size_t to)
+static inline void
+sec_clear_undefined (void *memory,
+                     size_t from,
+                     size_t to)
 {
+	char *ptr = memory;
 	ASSERT (from <= to);
-	memset ((char*)memory + from, 0, to - from);
-	return memory;
+#ifdef WITH_VALGRIND
+	VALGRIND_MAKE_MEM_UNDEFINED (ptr + from, to - from);
+#endif
+	memset (ptr + from, 0, to - from);
+#ifdef WITH_VALGRIND
+	VALGRIND_MAKE_MEM_UNDEFINED (ptr + from, to - from);
+#endif
 }
+static inline void
+sec_clear_noaccess (void *memory, size_t from, size_t to)
+{
+	char *ptr = memory;
+	ASSERT (from <= to);
+#ifdef WITH_VALGRIND
+	VALGRIND_MAKE_MEM_UNDEFINED (ptr + from, to - from);
+#endif
+	memset (ptr + from, 0, to - from);
+#ifdef WITH_VALGRIND
+	VALGRIND_MAKE_MEM_NOACCESS (ptr + from, to - from);
+#endif
+}
 
 static Cell*
 sec_neighbor_before (Block *block, Cell *cell)
@@ -459,7 +489,9 @@ sec_neighbor_after (Block *block, Cell *cell)
 }
 
 static void*
-sec_alloc (Block *block, size_t length)
+sec_alloc (Block *block,
+           const char *tag,
+           size_t length)
 {
 	Cell *cell, *other;
 	size_t n_words;
@@ -467,8 +499,9 @@ sec_alloc (Block *block, size_t length)
 
 	ASSERT (block);
 	ASSERT (length);
+	ASSERT (tag);
 
-	if (!block->unused)
+	if (!block->unused_cells)
 		return NULL;
 
 	/*
@@ -482,10 +515,10 @@ sec_alloc (Block *block, size_t length)
 	n_words = sec_size_to_words (length) + 2;
 
 	/* Look for a cell of at least our required size */
-	cell = block->unused;
+	cell = block->unused_cells;
 	while (cell->n_words < n_words) {
 		cell = cell->next;
-		if (cell == block->unused) {
+		if (cell == block->unused_cells) {
 			cell = NULL;
 			break;
 		}
@@ -494,7 +527,8 @@ sec_alloc (Block *block, size_t length)
 	if (!cell)
 		return NULL;
 
-	ASSERT (cell->allocated == 0);
+	ASSERT (cell->tag == NULL);
+	ASSERT (cell->requested == 0);
 	ASSERT (cell->prev);
 	ASSERT (cell->words);
 	sec_check_guards (cell);
@@ -516,10 +550,12 @@ sec_alloc (Block *block, size_t length)
 	}
 
 	if (cell->next)
-		sec_remove_cell_ring (&block->unused, cell);
+		sec_remove_cell_ring (&block->unused_cells, cell);
 
-	++block->used;
-	cell->allocated = length;
+	++block->n_used;
+	cell->tag = tag;
+	cell->requested = length;
+	sec_insert_cell_ring (&block->used_cells, cell);
 	memory = sec_cell_to_memory (cell);
 
 #ifdef WITH_VALGRIND
@@ -555,47 +591,83 @@ sec_free (Block *block, void *memory)
 #endif
 
 	sec_check_guards (cell);
-	sec_clear_memory (memory, 0, cell->allocated);
+	sec_clear_noaccess (memory, 0, cell->requested);
 
 	sec_check_guards (cell);
-	ASSERT (cell->next == NULL);
-	ASSERT (cell->prev == NULL);
-	ASSERT (cell->allocated > 0);
+	ASSERT (cell->requested > 0);
+	ASSERT (cell->tag != NULL);
 
-        /* Find previous unallocated neighbor, and merge if possible */
-        other = sec_neighbor_before (block, cell);
-        if (other && other->allocated == 0) {
-        	ASSERT (other->next && other->prev);
-        	other->n_words += cell->n_words;
-        	sec_write_guards (other);
-        	pool_free (cell);
-        	cell = other;
-        }
+	/* Remove from the used cell ring */
+	sec_remove_cell_ring (&block->used_cells, cell);
 
-        /* Find next unallocated neighbor, and merge if possible */
-        other = sec_neighbor_after (block, cell);
-        if (other && other->allocated == 0) {
-        	ASSERT (other->next && other->prev);
-        	other->n_words += cell->n_words;
-        	other->words = cell->words;
-        	if (cell->next)
-        		sec_remove_cell_ring (&block->unused, cell);
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
-        	sec_insert_cell_ring (&block->unused, cell);
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
 
-        cell->allocated = 0;
-        --block->used;
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
 
+static void
+memcpy_with_vbits (void *dest,
+                   void *src,
+                   size_t length)
+{
+#ifdef WITH_VALGRIND
+	int vbits_setup = 0;
+	void *vbits = NULL;
+
+	if (RUNNING_ON_VALGRIND) {
+		vbits = malloc (length);
+		if (vbits != NULL)
+			vbits_setup = VALGRIND_GET_VBITS (src, vbits, length);
+		VALGRIND_MAKE_MEM_DEFINED (src, length);
+	}
+#endif
+
+	memcpy (dest, src, length);
+
+#ifdef WITH_VALGRIND
+	if (vbits_setup == 1) {
+		VALGRIND_SET_VBITS (dest, vbits, length);
+		VALGRIND_SET_VBITS (src, vbits, length);
+	}
+	free (vbits);
+#endif
+}
+
 static void*
-sec_realloc (Block *block, void *memory, size_t length)
+sec_realloc (Block *block,
+             const char *tag,
+             void *memory,
+             size_t length)
 {
 	Cell *cell, *other;
 	word_t *word;
@@ -606,6 +678,7 @@ sec_realloc (Block *block, void *memory, size_t length
 	/* Standard realloc behavior, should have been handled elsewhere */
 	ASSERT (memory != NULL);
 	ASSERT (length > 0);
+	ASSERT (tag != NULL);
 
 	/* Dig out where the meta should be */
 	word = memory;
@@ -621,12 +694,11 @@ sec_realloc (Block *block, void *memory, size_t length
 
 	/* Validate that it's actually for real */
 	sec_check_guards (cell);
-	ASSERT (cell->allocated > 0);
-	ASSERT (cell->next == NULL);
-	ASSERT (cell->prev == NULL);
+	ASSERT (cell->requested > 0);
+	ASSERT (cell->tag != NULL);
 
 	/* The amount of valid data */
-	valid = cell->allocated;
+	valid = cell->requested;
 
 	/* How many words we actually want */
 	n_words = sec_size_to_words (length) + 2;
@@ -635,22 +707,18 @@ sec_realloc (Block *block, void *memory, size_t length
 	if (n_words <= cell->n_words) {
 
 		/* TODO: No shrinking behavior yet */
-		cell->allocated = length;
+		cell->requested = length;
 		alloc = sec_cell_to_memory (cell);
 
-#ifdef WITH_VALGRIND
-		VALGRIND_MAKE_MEM_DEFINED (alloc, length);
-#endif
-
 		/*
 		 * Even though we may be reusing the same cell, that doesn't
 		 * mean that the allocation is shrinking. It could have shrunk
 		 * and is now expanding back some.
 		 */
 		if (length < valid)
-			return sec_clear_memory (alloc, length, valid);
-		else
-			return alloc;
+			sec_clear_undefined (alloc, length, valid);
+
+		return alloc;
 	}
 
 	/* Need braaaaaiiiiiinsss... */
@@ -658,14 +726,14 @@ sec_realloc (Block *block, void *memory, size_t length
 
 		/* See if we have a neighbor who can give us some memory */
 		other = sec_neighbor_after (block, cell);
-		if (!other || other->allocated != 0)
+		if (!other || other->requested != 0)
 			break;
 
 		/* Eat the whole neighbor if not too big */
 		if (n_words - cell->n_words + WASTE >= other->n_words) {
 			cell->n_words += other->n_words;
 			sec_write_guards (cell);
-			sec_remove_cell_ring (&block->unused, other);
+			sec_remove_cell_ring (&block->unused_cells, other);
 			pool_free (other);
 
 		/* Steal from the neighbor */
@@ -679,20 +747,17 @@ sec_realloc (Block *block, void *memory, size_t length
 	}
 
 	if (cell->n_words >= n_words) {
-		cell->allocated = length;
+		cell->requested = length;
+		cell->tag = tag;
 		alloc = sec_cell_to_memory (cell);
-
-#ifdef WITH_VALGRIND
-		VALGRIND_MAKE_MEM_DEFINED (alloc, length);
-#endif
-
-		return sec_clear_memory (alloc, valid, length);
+		sec_clear_undefined (alloc, valid, length);
+		return alloc;
 	}
 
 	/* That didn't work, try alloc/free */
-	alloc = sec_alloc (block, length);
+	alloc = sec_alloc (block, tag, length);
 	if (alloc) {
-		memcpy (alloc, memory, valid);
+		memcpy_with_vbits (alloc, memory, valid);
 		sec_free (block, memory);
 	}
 
@@ -722,15 +787,14 @@ sec_allocated (Block *block, void *memory)
 	cell = *word;
 
 	sec_check_guards (cell);
-	ASSERT (cell->next == NULL);
-	ASSERT (cell->prev == NULL);
-	ASSERT (cell->allocated > 0);
+	ASSERT (cell->requested > 0);
+	ASSERT (cell->tag != NULL);
 
 #ifdef WITH_VALGRIND
 	VALGRIND_MAKE_MEM_NOACCESS (word, sizeof (word_t));
 #endif
 
-	return cell->allocated;
+	return cell->requested;
 }
 
 static void
@@ -739,6 +803,11 @@ sec_validate (Block *block)
 	Cell *cell;
 	word_t *word, *last;
 
+#ifdef WITH_VALGRIND
+	if (RUNNING_ON_VALGRIND)
+		return;
+#endif
+
 	word = block->words;
 	last = word + block->n_words;
 
@@ -753,15 +822,19 @@ sec_validate (Block *block)
 		sec_check_guards (cell);
 
 		/* Is it an allocated block? */
-		if (cell->allocated > 0) {
-			ASSERT (cell->next == NULL);
-			ASSERT (cell->prev == NULL);
-			ASSERT (cell->allocated <= (cell->n_words - 2) * sizeof (word_t));
+		if (cell->requested > 0) {
+			ASSERT (cell->tag != NULL);
+			ASSERT (cell->next != NULL);
+			ASSERT (cell->prev != NULL);
+			ASSERT (cell->next->prev == cell);
+			ASSERT (cell->prev->next == cell);
+			ASSERT (cell->requested <= (cell->n_words - 2) * sizeof (word_t));
 
-			/* An unused block */
+		/* An unused block */
 		} else {
-			ASSERT (cell->next);
-			ASSERT (cell->prev);
+			ASSERT (cell->tag == NULL);
+			ASSERT (cell->next != NULL);
+			ASSERT (cell->prev != NULL);
 			ASSERT (cell->next->prev == cell);
 			ASSERT (cell->prev->next == cell);
 		}
@@ -777,13 +850,15 @@ sec_validate (Block *block)
  */
 
 static void*
-sec_acquire_pages (size_t *sz)
+sec_acquire_pages (size_t *sz,
+                   const char *during_tag)
 {
 	void *pages;
 	unsigned long pgsize;
 
 	ASSERT (sz);
 	ASSERT (*sz);
+	ASSERT (during_tag);
 
 	/* Make sure sz is a multiple of the page size */
 	pgsize = getpagesize ();
@@ -792,18 +867,18 @@ sec_acquire_pages (size_t *sz)
 #if defined(HAVE_MLOCK)
 	pages = mmap (0, *sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
 	if (pages == MAP_FAILED) {
-		if (lock_warning && egg_secure_warnings)
-			fprintf (stderr, "couldn't map %lu bytes of private memory: %s\n",
-			         (unsigned long)*sz, strerror (errno));
-		lock_warning = 0;
+		if (show_warning && egg_secure_warnings)
+			fprintf (stderr, "couldn't map %lu bytes of memory (%s): %s\n",
+			         (unsigned long)*sz, during_tag, strerror (errno));
+		show_warning = 0;
 		return NULL;
 	}
 
 	if (mlock (pages, *sz) < 0) {
-		if (lock_warning && egg_secure_warnings && errno != EPERM) {
-			fprintf (stderr, "couldn't lock %lu bytes of private memory: %s\n",
-			         (unsigned long)*sz, strerror (errno));
-			lock_warning = 0;
+		if (show_warning && egg_secure_warnings && errno != EPERM) {
+			fprintf (stderr, "couldn't lock %lu bytes of memory (%s): %s\n",
+			         (unsigned long)*sz, during_tag, strerror (errno));
+			show_warning = 0;
 		}
 		munmap (pages, *sz);
 		return NULL;
@@ -811,13 +886,13 @@ sec_acquire_pages (size_t *sz)
 
 	DEBUG_ALLOC ("gkr-secure-memory: new block ", *sz);
 
-	lock_warning = 1;
+	show_warning = 1;
 	return pages;
 
 #else
-	if (lock_warning && egg_secure_warnings)
+	if (show_warning && egg_secure_warnings)
 		fprintf (stderr, "your system does not support private memory");
-	lock_warning = 0;
+	show_warning = 0;
 	return NULL;
 #endif
 
@@ -850,15 +925,17 @@ sec_release_pages (void *pages, size_t sz)
 static Block *all_blocks = NULL;
 
 static Block*
-sec_block_create (size_t size)
+sec_block_create (size_t size,
+                  const char *during_tag)
 {
 	Block *block;
 	Cell *cell;
 
-#if FORCE_FALLBACK_MEMORY
+	ASSERT (during_tag);
+
 	/* We can force all all memory to be malloced */
-	return NULL;
-#endif
+	if (getenv ("SECMEM_FORCE_FALLBACK"))
+		return NULL;
 
 	block = pool_alloc ();
 	if (!block)
@@ -874,7 +951,7 @@ sec_block_create (size_t size)
 	if (size < DEFAULT_BLOCK_SIZE)
 		size = DEFAULT_BLOCK_SIZE;
 
-	block->words = sec_acquire_pages (&size);
+	block->words = sec_acquire_pages (&size, during_tag);
 	block->n_words = size / sizeof (word_t);
 	if (!block->words) {
 		pool_free (block);
@@ -889,9 +966,9 @@ sec_block_create (size_t size)
 	/* The first cell to allocate from */
 	cell->words = block->words;
 	cell->n_words = block->n_words;
-	cell->allocated = 0;
+	cell->requested = 0;
 	sec_write_guards (cell);
-	sec_insert_cell_ring (&block->unused, cell);
+	sec_insert_cell_ring (&block->unused_cells, cell);
 
 	block->next = all_blocks;
 	all_blocks = block;
@@ -907,7 +984,7 @@ sec_block_destroy (Block *block)
 
 	ASSERT (block);
 	ASSERT (block->words);
-	ASSERT (block->used == 0);
+	ASSERT (block->n_used == 0);
 
 	/* Remove from the list */
 	for (at = &all_blocks, bl = *at; bl; at = &bl->next, bl = *at) {
@@ -919,11 +996,12 @@ sec_block_destroy (Block *block)
 
 	/* Must have been found */
 	ASSERT (bl == block);
+	ASSERT (block->used_cells == NULL);
 
 	/* Release all the meta data cells */
-	while (block->unused) {
-		cell = block->unused;
-		sec_remove_cell_ring (&block->unused, cell);
+	while (block->unused_cells) {
+		cell = block->unused_cells;
+		sec_remove_cell_ring (&block->unused_cells, cell);
 		pool_free (cell);
 	}
 
@@ -938,17 +1016,16 @@ sec_block_destroy (Block *block)
  */
 
 void*
-egg_secure_alloc (size_t length)
+egg_secure_alloc_full (const char *tag,
+                       size_t length,
+                       int flags)
 {
-	return egg_secure_alloc_full (length, GKR_SECURE_USE_FALLBACK);
-}
-
-void*
-egg_secure_alloc_full (size_t length, int flags)
-{
 	Block *block;
 	void *memory = NULL;
 
+	if (tag == NULL)
+		tag = "?";
+
 	if (length > 0xFFFFFFFF / 2) {
 		if (egg_secure_warnings)
 			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n",
@@ -963,16 +1040,16 @@ egg_secure_alloc_full (size_t length, int flags)
 	DO_LOCK ();
 
 		for (block = all_blocks; block; block = block->next) {
-			memory = sec_alloc (block, length);
+			memory = sec_alloc (block, tag, length);
 			if (memory)
 				break;
 		}
 
 		/* None of the current blocks have space, allocate new */
 		if (!memory) {
-			block = sec_block_create (length);
+			block = sec_block_create (length, tag);
 			if (block)
-				memory = sec_alloc (block, length);
+				memory = sec_alloc (block, tag, length);
 		}
 
 #ifdef WITH_VALGRIND
@@ -982,8 +1059,8 @@ egg_secure_alloc_full (size_t length, int flags)
 
 	DO_UNLOCK ();
 
-	if (!memory && (flags & GKR_SECURE_USE_FALLBACK)) {
-		memory = egg_memory_fallback (NULL, length);
+	if (!memory && (flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback != NULL) {
+		memory = EGG_SECURE_GLOBALS.fallback (NULL, length);
 		if (memory) /* Our returned memory is always zeroed */
 			memset (memory, 0, length);
 	}
@@ -995,19 +1072,19 @@ egg_secure_alloc_full (size_t length, int flags)
 }
 
 void*
-egg_secure_realloc (void *memory, size_t length)
+egg_secure_realloc_full (const char *tag,
+                         void *memory,
+                         size_t length,
+                         int flags)
 {
-	return egg_secure_realloc_full (memory, length, GKR_SECURE_USE_FALLBACK);
-}
-
-void*
-egg_secure_realloc_full (void *memory, size_t length, int flags)
-{
 	Block *block = NULL;
 	size_t previous = 0;
 	int donew = 0;
 	void *alloc = NULL;
 
+	if (tag == NULL)
+		tag = "?";
+
 	if (length > 0xFFFFFFFF / 2) {
 		if (egg_secure_warnings)
 			fprintf (stderr, "tried to allocate an insane amount of memory: %lu\n",
@@ -1016,7 +1093,7 @@ egg_secure_realloc_full (void *memory, size_t length, 
 	}
 
 	if (memory == NULL)
-		return egg_secure_alloc_full (length, flags);
+		return egg_secure_alloc_full (tag, length, flags);
 	if (!length) {
 		egg_secure_free_full (memory, flags);
 		return NULL;
@@ -1034,7 +1111,7 @@ egg_secure_realloc_full (void *memory, size_t length, 
 				VALGRIND_FREELIKE_BLOCK (memory, sizeof (word_t));
 #endif
 
-				alloc = sec_realloc (block, memory, length);
+				alloc = sec_realloc (block, tag, memory, length);
 
 #ifdef WITH_VALGRIND
 				/* Now tell valgrind about either the new block or old one */
@@ -1050,31 +1127,31 @@ egg_secure_realloc_full (void *memory, size_t length, 
 		if (block && !alloc)
 			donew = 1;
 
-		if (block && block->used == 0)
+		if (block && block->n_used == 0)
 			sec_block_destroy (block);
 
 	DO_UNLOCK ();
 
 	if (!block) {
-		if ((flags & GKR_SECURE_USE_FALLBACK)) {
+		if ((flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback) {
 			/*
 			 * In this case we can't zero the returned memory,
 			 * because we don't know what the block size was.
 			 */
-			return egg_memory_fallback (memory, length);
+			return EGG_SECURE_GLOBALS.fallback (memory, length);
 		} else {
 			if (egg_secure_warnings)
-				fprintf (stderr, "memory does not belong to gnome-keyring: 0x%08lx\n",
+				fprintf (stderr, "memory does not belong to secure memory pool: 0x%08lx\n",
 				         (unsigned long)memory);
-			ASSERT (0 && "memory does does not belong to gnome-keyring");
+			ASSERT (0 && "memory does does not belong to secure memory pool");
 			return NULL;
 		}
 	}
 
 	if (donew) {
-		alloc = egg_secure_alloc_full (length, flags);
+		alloc = egg_secure_alloc_full (tag, length, flags);
 		if (alloc) {
-			memcpy (alloc, memory, previous);
+			memcpy_with_vbits (alloc, memory, previous);
 			egg_secure_free_full (memory, flags);
 		}
 	}
@@ -1088,7 +1165,7 @@ egg_secure_realloc_full (void *memory, size_t length, 
 void
 egg_secure_free (void *memory)
 {
-	egg_secure_free_full (memory, GKR_SECURE_USE_FALLBACK);
+	egg_secure_free_full (memory, EGG_SECURE_USE_FALLBACK);
 }
 
 void
@@ -1109,26 +1186,26 @@ egg_secure_free_full (void *memory, int flags)
 
 #ifdef WITH_VALGRIND
 		/* We like valgrind's warnings, so give it a first whack at checking for errors */
-		if (block != NULL || !(flags & GKR_SECURE_USE_FALLBACK))
+		if (block != NULL || !(flags & EGG_SECURE_USE_FALLBACK))
 			VALGRIND_FREELIKE_BLOCK (memory, sizeof (word_t));
 #endif
 
 		if (block != NULL) {
 			sec_free (block, memory);
-			if (block->used == 0)
+			if (block->n_used == 0)
 				sec_block_destroy (block);
 		}
 
 	DO_UNLOCK ();
 
 	if (!block) {
-		if ((flags & GKR_SECURE_USE_FALLBACK)) {
-			egg_memory_fallback (memory, 0);
+		if ((flags & EGG_SECURE_USE_FALLBACK) && EGG_SECURE_GLOBALS.fallback) {
+			EGG_SECURE_GLOBALS.fallback (memory, 0);
 		} else {
 			if (egg_secure_warnings)
-				fprintf (stderr, "memory does not belong to gnome-keyring: 0x%08lx\n",
+				fprintf (stderr, "memory does not belong to secure memory pool: 0x%08lx\n",
 				         (unsigned long)memory);
-			ASSERT (0 && "memory does does not belong to gnome-keyring");
+			ASSERT (0 && "memory does does not belong to secure memory pool");
 		}
 	}
 }
@@ -1164,26 +1241,78 @@ egg_secure_validate (void)
 	DO_UNLOCK ();
 }
 
-void
-egg_secure_dump_blocks (void)
+
+static egg_secure_rec *
+records_for_ring (Cell *cell_ring,
+                  egg_secure_rec *records,
+                  unsigned int *count,
+                  unsigned int *total)
 {
+	egg_secure_rec *new_rec;
+	unsigned int allocated = *count;
+	Cell *cell;
+
+	cell = cell_ring;
+	do {
+		if (*count >= allocated) {
+			new_rec = realloc (records, sizeof (egg_secure_rec) * (allocated + 32));
+			if (new_rec == NULL) {
+				*count = 0;
+				free (records);
+				return NULL;
+			} else {
+				records = new_rec;
+				allocated += 32;
+			}
+		}
+
+		if (cell != NULL) {
+			records[*count].request_length = cell->requested;
+			records[*count].block_length = cell->n_words * sizeof (word_t);
+			records[*count].tag = cell->tag;
+			(*count)++;
+			(*total) += cell->n_words;
+			cell = cell->next;
+		}
+	} while (cell != NULL && cell != cell_ring);
+
+	return records;
+}
+
+egg_secure_rec *
+egg_secure_records (unsigned int *count)
+{
+	egg_secure_rec *records = NULL;
 	Block *block = NULL;
+	unsigned int total;
 
+	*count = 0;
+
 	DO_LOCK ();
 
-		/* Find out where it belongs to */
-		for (block = all_blocks; block; block = block->next) {
-			fprintf (stderr, "----------------------------------------------------\n");
-			fprintf (stderr, "  BLOCK at: 0x%08lx  len: %lu\n", (unsigned long)block,
-			         (unsigned long)block->n_words * sizeof (word_t));
-			fprintf (stderr, "\n");
+		for (block = all_blocks; block != NULL; block = block->next) {
+			total = 0;
+
+			records = records_for_ring (block->unused_cells, records, count, &total);
+			if (records == NULL)
+				break;
+			records = records_for_ring (block->used_cells, records, count, &total);
+			if (records == NULL)
+				break;
+
+			/* Make sure this actualy accounts for all memory */
+			ASSERT (total == block->n_words);
 		}
 
 	DO_UNLOCK ();
+
+	return records;
 }
 
 char*
-egg_secure_strdup (const char *str)
+egg_secure_strdup_full (const char *tag,
+                        const char *str,
+                        int options)
 {
 	size_t len;
 	char *res;
@@ -1192,11 +1321,33 @@ egg_secure_strdup (const char *str)
 		return NULL;
 
 	len = strlen (str) + 1;
-	res = (char*)egg_secure_alloc (len);
+	res = (char *)egg_secure_alloc_full (tag, len, options);
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
@@ -1205,11 +1356,11 @@ egg_secure_clear (void *p, size_t length)
 	if (p == NULL)
 		return;
 
-	vp = (volatile char*)p;
-	while (length) {
-		*vp = 0xAA;
-		vp++;
-		length--;
+        vp = (volatile char*)p;
+        while (length) {
+	        *vp = 0xAA;
+	        vp++;
+	        length--;
 	}
 }
 
@@ -1231,5 +1382,5 @@ egg_secure_strfree (char *str)
 	 */
 
 	egg_secure_strclear (str);
-	egg_secure_free_full (str, GKR_SECURE_USE_FALLBACK);
+	egg_secure_free_full (str, EGG_SECURE_USE_FALLBACK);
 }
