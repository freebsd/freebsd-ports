--- agent/mibgroup/ucd-snmp/disk.c.orig	Wed Apr  3 07:57:57 2002
+++ agent/mibgroup/ucd-snmp/disk.c	Thu Aug 29 12:11:17 2002
@@ -340,7 +340,7 @@
   double totalblks, free, used, avail, availblks;
 #else
   static long avail;
-#ifdef STRUCT_STATVFS_HAS_F_FILES
+#if defined(HAVE_UFS_FFS_FS_H) || defined(STRUCT_STATVFS_HAS_F_FILES)
   int percent_inode;
 #endif
 #endif
@@ -424,6 +424,11 @@
     (int) ((double) (vfs.f_files - vfs.f_ffree) /
            (double) (vfs.f_files - (vfs.f_ffree - vfs.f_favail)) * 100.0 + 0.5);
 #endif
+#if defined(HAVE_UFS_FFS_FS_H) && !defined(STRUCT_STATVFS_HAS_F_FILES)
+  percent_inode = vfs.f_files == 0 ? 100.0 :
+    (int) ((double) (vfs.f_files - vfs.f_ffree) /
+	   (double) (vfs.f_files) * 100.0 + 0.5);
+#endif
   switch (vp->magic) {
     case DISKTOTAL:
       long_ret = vfs.f_blocks * (vfs.f_bsize / 1024);
@@ -444,7 +449,7 @@
     case DISKPERCENT:
       long_ret = percent;
       return ((u_char *) (&long_ret));
-#ifdef STRUCT_STATVFS_HAS_F_FILES
+#if defined(HAVE_UFS_FFS_FS_H) || defined(STRUCT_STATVFS_HAS_F_FILES)
     case DISKPERCENTNODE:
       long_ret = percent_inode;
       return ((u_char *) (&long_ret));
