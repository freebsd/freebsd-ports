diff -Nur src/dso.c src/dso.c
--- src/dso.c	2013-02-19 23:54:34.000000000 +0200
+++ src/dso.c	2013-02-19 23:50:31.000000000 +0200
@@ -33,7 +33,9 @@
 #define USE_SELINUX
 #endif
 
+#if HAVE_SYS_XATTR_H
 #include <sys/xattr.h>
+#endif
 
 #define RELOCATE_SCN(shf) \
   ((shf) & (SHF_WRITE | SHF_ALLOC | SHF_EXECINSTR))
@@ -1699,6 +1701,7 @@
 static int
 copy_xattrs (const char *temp_name, const char *name, int ignore_errors)
 {
+#if HAVE_SYS_XATTR_H
   ssize_t sz = listxattr (name, NULL, 0), valsz = 0;
   char *list = NULL, *end, *p, *val = NULL, *newval;
 
@@ -1777,6 +1780,8 @@
   free (val);
   free (list);
   return 1;
+#endif
+  return 0;
 }
 
 static int
@@ -1816,9 +1821,17 @@
 }
 
 int
+#ifdef __LINUX__
 copy_fd_to_file (int fdin, const char *name, struct stat64 *st)
+#else
+copy_fd_to_file (int fdin, const char *name, struct stat *st)
+#endif
 {
+#ifdef __LINUX__
   struct stat64 stt;
+#else
+  struct stat stt;
+#endif
   off_t off = 0;
   int err, fdout;
   struct utimbuf u;
@@ -1828,7 +1841,11 @@
   else
     fdout = open (name, O_WRONLY | O_CREAT, 0600);
   if (fdout != -1
+#ifdef __LINUX__
       && fstat64 (fdin, &stt) >= 0
+#else
+      && fstat (fdin, &stt) >= 0
+#endif
       && send_file (fdout, fdin, &off, stt.st_size) == stt.st_size)
     {
       if (fchown (fdout, st->st_uid, st->st_gid) >= 0)
@@ -1863,7 +1880,11 @@
     {
       char *name1, *name2;
       struct utimbuf u;
+#ifdef __LINUX__
       struct stat64 st;
+#else
+      struct stat st;
+#endif
       int fdin;
 
       switch (write_dso (dso))
@@ -1879,9 +1900,15 @@
 	  break;
 	}
 
-      name1 = strdupa (dso->filename);
-      name2 = strdupa (dso->temp_filename);
+      name1 = alloca(strlen(dso->filename) + 1);
+      strcpy(name1, dso->filename);
+      name2 = alloca(strlen(dso->temp_filename) + 1);
+      strcpy(name2, dso->temp_filename);
+#if __LINUX__
       if (fstat64 (dso->fdro, &st) < 0)
+#else
+      if (fstat (dso->fdro, &st) < 0)
+#endif
 	{
 	  error (0, errno, "Could not stat %s", dso->filename);
 	  close_dso (dso);
