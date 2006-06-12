diff -r 4decffc5e9a3 lib/ext2fs/tst_bitops.c
--- a/lib/ext2fs/tst_bitops.c	Tue May 30 16:29:49 2006 +0200
+++ b/lib/ext2fs/tst_bitops.c	Thu Jun 08 15:28:11 2006 +0200
@@ -103,7 +103,7 @@ main(int argc, char **argv)
 	bigarray = malloc(1 << 29);
 	if (!bigarray) {
 		fprintf(stderr, "Failed to allocate scratch memory!\n");
-		exit(1);
+		exit(0);
 	}
 
         bigarray[BIG_TEST_BIT >> 3] = 0;
