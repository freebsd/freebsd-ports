--- ./lib/ext2fs/tst_bitops.c.orig	2012-07-06 15:37:27.000000000 +0200
+++ ./lib/ext2fs/tst_bitops.c	2014-01-06 23:26:48.000000000 +0100
@@ -104,7 +104,7 @@
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
