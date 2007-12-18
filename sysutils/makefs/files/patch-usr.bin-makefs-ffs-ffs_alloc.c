--- ./netbsdsrc/usr.sbin/makefs/ffs/ffs_alloc.c~	2004-07-04 23:17:39.000000000 -0600
+++ ./netbsdsrc/usr.sbin/makefs/ffs/ffs_alloc.c	2007-12-16 19:44:22.000000000 -0700
@@ -120,7 +120,10 @@
 		cg = dtog(fs, bpref);
 	bno = ffs_hashalloc(ip, cg, bpref, size, ffs_alloccg);
 	if (bno > 0) {
-		DIP(ip, blocks) += size / DEV_BSIZE;
+		if (ip->i_fs->fs_magic == FS_UFS1_MAGIC)
+			ip->i_ffs1_blocks += size / DEV_BSIZE;
+		else
+			ip->i_ffs2_blocks += size / DEV_BSIZE;
 		*bnp = bno;
 		return (0);
 	}
