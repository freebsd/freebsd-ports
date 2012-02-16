--- ./lib/ext2fs/tst_bitops.c.orig	2011-09-18 20:06:51.000000000 +0200
+++ ./lib/ext2fs/tst_bitops.c	2012-02-16 00:35:12.000000000 +0100
@@ -104,7 +104,7 @@
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
