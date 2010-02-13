--- agent/mibgroup/ucd-snmp/disk.c.orig	2003-05-14 10:17:46.000000000 +0000
+++ agent/mibgroup/ucd-snmp/disk.c	2008-04-30 06:01:57.000000000 +0000
@@ -346,7 +346,7 @@
   double totalblks, free, used, avail, availblks;
 #else
   static long avail;
-#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_FILES)
+#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_FILES) || defined(HAVE_UFS_FFS_FS_H)
   int percent_inode;
 #endif
 #endif
@@ -425,7 +425,7 @@
   iserror = (disks[disknum].minimumspace >= 0 ?
              avail < disks[disknum].minimumspace :
              100-percent <= disks[disknum].minpercent) ? 1 : 0;
-#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_AVAIL)
+#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_AVAIL) || defined(HAVE_UFS_FFS_FS_H)
   percent_inode = vfs.f_favail <= 0 ? 100 :
     (int) ((double) (vfs.f_files - vfs.f_ffree) /
            (double) (vfs.f_files - (vfs.f_ffree - vfs.f_favail)) * 100.0 + 0.5);
@@ -436,6 +436,11 @@
            (double) (vfs.f_files) * 100.0 + 0.5);
 #endif
 #endif
+#if defined(HAVE_UFS_FFS_FS_H) && !defined(STRUCT_STATVFS_HAS_F_FILES)
+  percent_inode = vfs.f_files == 0 ? 100.0 :
+    (int) ((double) (vfs.f_files - vfs.f_ffree) /
+	   (double) (vfs.f_files) * 100.0 + 0.5);
+#endif
   switch (vp->magic) {
     case DISKTOTAL:
       long_ret = vfs.f_blocks * (vfs.f_bsize / 1024);
@@ -456,7 +461,7 @@
     case DISKPERCENT:
       long_ret = percent;
       return ((u_char *) (&long_ret));
-#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_FILES)
+#if defined(STRUCT_STATVFS_HAS_F_FILES) || defined(STRUCT_STATFS_HAS_F_FILES) || defined(HAVE_UFS_FFS_FS_H)
     case DISKPERCENTNODE:
       long_ret = percent_inode;
       return ((u_char *) (&long_ret));
