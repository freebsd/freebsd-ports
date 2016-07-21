--- misc/create_inode.c.orig	2016-06-08 21:39:43 UTC
+++ misc/create_inode.c
@@ -450,7 +450,7 @@ static errcode_t try_lseek_copy(ext2_fil
 {
 	off_t data = 0, hole;
 	off_t data_blk, hole_blk;
-	errcode_t err;
+	errcode_t err = 0;
 
 	/* Try to use SEEK_DATA and SEEK_HOLE */
 	while (data < statbuf->st_size) {
