--- lib/ext2fs/blkmap64_rb.c.orig	2021-01-29 22:02:31 UTC
+++ lib/ext2fs/blkmap64_rb.c
@@ -12,6 +12,7 @@
 #include "config.h"
 #include <stdio.h>
 #include <string.h>
+#include <inttypes.h>
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -907,7 +908,7 @@ static void rb_print_stats(ext2fs_generic_bitmap_64 bi
 	struct ext2fs_rb_private *bp;
 	struct rb_node *node = NULL;
 	struct bmap_rb_extent *ext;
-	__u64 count = 0;
+	unsigned long long count = 0;
 	__u64 max_size = 0;
 	__u64 min_size = ULONG_MAX;
 	__u64 size = 0, avg_size = 0;
@@ -951,12 +952,12 @@ static void rb_print_stats(ext2fs_generic_bitmap_64 bi
 	fprintf(stderr, "%16llu extents (%llu bytes)\n",
 		count, ((count * sizeof(struct bmap_rb_extent)) +
 			sizeof(struct ext2fs_rb_private)));
- 	fprintf(stderr, "%16llu bits minimum size\n",
+ 	fprintf(stderr, "%16" PRIu64 " bits minimum size\n",
 		min_size);
-	fprintf(stderr, "%16llu bits maximum size\n"
-		"%16llu bits average size\n",
+	fprintf(stderr, "%16" PRIu64 " bits maximum size\n"
+		"%16" PRIu64 " bits average size\n",
 		max_size, avg_size);
-	fprintf(stderr, "%16llu bits set in bitmap (out of %llu)\n", size,
+	fprintf(stderr, "%16" PRIu64 " bits set in bitmap (out of %" PRIu64 ")\n", size,
 		bitmap->real_end - bitmap->start);
 	fprintf(stderr,
 		"%16.4lf memory / bitmap bit memory ratio (bitarray = 1)\n",
