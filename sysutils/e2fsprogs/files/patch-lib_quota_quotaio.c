--- ./lib/quota/quotaio.c~	2011-11-27 19:22:10.000000000 -0600
+++ ./lib/quota/quotaio.c	2012-02-16 15:08:31.757648919 -0600
@@ -143,7 +143,7 @@ errcode_t quota_inode_truncate(ext2_fils
 
 	inode.i_dtime = fs->now ? fs->now : time(0);
 	if (!ext2fs_inode_has_valid_blocks2(fs, &inode))
-		return;
+		return err;
 
 	ext2fs_block_iterate3(fs, ino, BLOCK_FLAG_READ_ONLY, NULL,
 			      release_blocks_proc, NULL);--- ./usr/ports/sysutils/e2fsprogs/files/patch-lib_quota_quotaio.c.orig	2012-02-17 22:18:01.000000000 +0100
