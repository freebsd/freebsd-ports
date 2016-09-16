--- lib/ext2fs/tst_bitops.c.orig	2014-10-16 00:29:23 UTC
+++ lib/ext2fs/tst_bitops.c
@@ -104,7 +104,7 @@ int main(int argc, char **argv)
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
