--- xdf.H	Mon Dec 22 00:10:05 1997
+++ ../xdf/xdf.H	Fri Nov  8 21:17:34 2002
@@ -51,14 +51,14 @@

 /*{{{  Variables  */
 char* prgname;
-FILE* fstab;
-FILE* mtab;
-struct mntent* table;
+struct fstab* fstab;
+struct statfs* mtab;
+struct statfs* table;
 struct statfs stat_buffer;
 int mountpoints;
 Partition* par_table[50];
 struct itimerval timer;
-
+int mntcount;

 #ifdef NO_ISO9660
 int no_iso9660 = TRUE;
