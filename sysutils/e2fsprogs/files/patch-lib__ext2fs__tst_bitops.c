--- lib/ext2fs/tst_bitops.c.orig	2014-06-25 19:19:15 UTC
+++ lib/ext2fs/tst_bitops.c
@@ -104,7 +104,7 @@
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
