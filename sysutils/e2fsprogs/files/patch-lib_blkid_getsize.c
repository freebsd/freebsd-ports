diff -r 0fbbbe379fea -r 05c2c6855f62 lib/blkid/getsize.c
--- a/lib/blkid/getsize.c	Tue May 30 01:48:51 2006 +0200
+++ b/lib/blkid/getsize.c	Tue May 30 05:08:02 2006 +0200
@@ -133,20 +133,22 @@ blkid_loff_t blkid_get_dev_size(int fd)
 		return (blkid_loff_t)this_floppy.size << 9;
 #endif
 #ifdef HAVE_SYS_DISKLABEL_H
-#if 0
 	/*
-	 * This should work in theory but I haven't tested it.  Anyone
-	 * on a BSD system want to test this for me?  In the meantime,
-	 * binary search mechanism should work just fine.
+	 * This code works for FreeBSD 4.11 i386, except for the full device
+	 * (such as /dev/ad0). It doesn't work properly for newer FreeBSD
+	 * though. FreeBSD >= 5.0 should be covered by the DIOCGMEDIASIZE
+	 * above however.
+	 *
+	 * Note that FreeBSD >= 4.0 has disk devices as unbuffered (raw,
+	 * character) devices, so we need to check for S_ISCHR, too.
 	 */
-	if ((fstat(fd, &st) >= 0) && S_ISBLK(st.st_mode))
+	if ((fstat(fd, &st) >= 0) && (S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode)))
 		part = st.st_rdev & 7;
 	if (part >= 0 && (ioctl(fd, DIOCGDINFO, (char *)&lab) >= 0)) {
 		pp = &lab.d_partitions[part];
 		if (pp->p_size)
 			return pp->p_size << 9;
 	}
-#endif
 #endif /* HAVE_SYS_DISKLABEL_H */
 	{
 #ifdef HAVE_FSTAT64
