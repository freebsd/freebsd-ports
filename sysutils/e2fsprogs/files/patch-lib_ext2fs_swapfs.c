Author: Theodore Ts'o <tytso@mit.edu>

    libext2fs: avoid array buffer overruns caused by insane directory blocks
    
    Reported-by: canardo909@gmx.com
    Signed-off-by: Theodore Ts'o <tytso@mit.edu>

Additionally line 441 was modified to "return 0" after e-mail exchange
between Canardo and Theodore. // mandree@FreeBSD.org 2020-02-17

--- lib/ext2fs/swapfs.c.orig	2020-01-06 23:10:17 UTC
+++ lib/ext2fs/swapfs.c
@@ -416,10 +416,11 @@ errcode_t ext2fs_dirent_swab_in2(ext2_filsys fs, char 
 	errcode_t	retval;
 	char		*p, *end;
 	struct ext2_dir_entry *dirent;
-	unsigned int	name_len, rec_len;
+	unsigned int	name_len, rec_len, left;
 
 	p = (char *) buf;
 	end = (char *) buf + size;
+	left = size;
 	while (p < end-8) {
 		dirent = (struct ext2_dir_entry *) p;
 		dirent->inode = ext2fs_swab32(dirent->inode);
@@ -436,6 +437,9 @@ errcode_t ext2fs_dirent_swab_in2(ext2_filsys fs, char 
 			retval = EXT2_ET_DIR_CORRUPTED;
 		} else if (((name_len & 0xFF) + 8) > rec_len)
 			retval = EXT2_ET_DIR_CORRUPTED;
+		if (rec_len > left)
+			return 0;
+		left -= rec_len;
 		p += rec_len;
 	}
 
@@ -452,11 +456,12 @@ errcode_t ext2fs_dirent_swab_out2(ext2_filsys fs, char
 {
 	errcode_t	retval;
 	char		*p, *end;
-	unsigned int	rec_len;
+	unsigned int	rec_len, left;
 	struct ext2_dir_entry *dirent;
 
 	p = buf;
 	end = buf + size;
+	left = size;
 	while (p < end) {
 		dirent = (struct ext2_dir_entry *) p;
 		retval = ext2fs_get_rec_len(fs, dirent, &rec_len);
@@ -471,6 +476,9 @@ errcode_t ext2fs_dirent_swab_out2(ext2_filsys fs, char
 		dirent->inode = ext2fs_swab32(dirent->inode);
 		dirent->rec_len = ext2fs_swab16(dirent->rec_len);
 		dirent->name_len = ext2fs_swab16(dirent->name_len);
+		if (rec_len > size)
+			return EXT2_ET_DIR_CORRUPTED;
+		size -= rec_len;
 
 		if (flags & EXT2_DIRBLOCK_V2_STRUCT)
 			dirent->name_len = ext2fs_swab16(dirent->name_len);
