--- ./lib/ext2fs/tst_bitops.c.orig	2012-03-18 19:18:33.000000000 +0100
+++ ./lib/ext2fs/tst_bitops.c	2012-04-01 17:15:49.000000000 +0200
@@ -104,7 +104,7 @@
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
