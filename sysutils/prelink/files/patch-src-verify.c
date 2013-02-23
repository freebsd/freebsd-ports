diff -Nur src/verify.c prelink-port/src/verify.c
--- src/verify.c	2013-02-19 23:54:34.000000000 +0200
+++ src/verify.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,7 +17,13 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_ENDIAN_H
 #include <endian.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#endif
+
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
@@ -44,7 +50,9 @@
       q = p + count;
       while (p != q)
 	{
-	  n = TEMP_FAILURE_RETRY (write (outfd, p, q - p));
+          do {
+	    n = write (outfd, p, q - p);
+          } while (n < 0 && errno == EINTR);
 	  if (n <= 0)
 	    {
 	      munmap (b, count);
@@ -65,7 +73,9 @@
       q = buf + len;
       while (p != q)
 	{
-	  n = TEMP_FAILURE_RETRY (read (infd, p, q - p));
+	  do {
+	    n = read (infd, p, q - p);
+          } while (n < 0 && errno == EINTR);
 	  if (n <= 0)
 	    return -1;
 	  p += n;
@@ -73,7 +83,9 @@
       p = buf;
       while (p != q)
 	{
-	  n = TEMP_FAILURE_RETRY (write (outfd, p, q - p));
+	  do {
+	    n = write (outfd, p, q - p);
+	  } while (n < 0 && errno == EINTR);
 	  if (n <= 0)
 	    return -1;
 	  p += n;
@@ -107,7 +119,9 @@
       q = b + len;
       while (p != q)
 	{
-	  n = TEMP_FAILURE_RETRY (read (fd, p, q - p));
+	  do {
+	    n = read (fd, p, q - p);
+	  } while (n < 0 && errno == EINTR);
 	  if (n < 0)
 	    return 1;
 	  p += n;
@@ -123,9 +137,17 @@
 {
   off_t off;
   size_t cnt;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
 
+#if __LINUX__
   if (fstat64 (fd, &st) < 0)
+#else
+  if (fstat (fd, &st) < 0)
+#endif
     {
       error (0, errno, "%s: couldn't fstat temporary file", filename);
       return 1;
@@ -186,14 +208,22 @@
 {
   DSO *dso = NULL, *dso2 = NULL;
   int fd = -1, fdorig = -1, fdundone = -1, undo, ret;
+#if __LINUX__
   struct stat64 st, st2;
+#else
+  struct stat st, st2;
+#endif
   struct prelink_entry *ent;
   GElf_Addr base;
   char buffer[32768], buffer2[32768];
   size_t count;
   char *p, *q;
 
+#if __LINUX__
   if (stat64 (filename, &st) < 0)
+#else
+  if (stat (filename, &st) < 0)
+#endif
     error (EXIT_FAILURE, errno, "Couldn't stat %s", filename);
 
   dso = open_dso (filename);
@@ -214,7 +244,11 @@
   if (undo == dso->ehdr.e_shnum)
     goto not_prelinked;
 
+#if __LINUX__
   if (fstat64 (dso->fd, &st2) < 0)
+#else
+  if (fstat (dso->fd, &st2) < 0)
+#endif
     {
       error (0, errno, "Couldn't fstat %s", filename);
       goto failure;
@@ -326,7 +360,11 @@
   close_dso (dso2);
   dso2 = NULL;
 
+#if __LINUX__
   if (fstat64 (fdorig, &st2) < 0)
+#else
+  if (fstat (fdorig, &st2) < 0)
+#endif
     {
       error (0, errno, "Couldn't fstat %s", filename);
       goto failure;
@@ -339,7 +377,11 @@
       goto failure;
     }
 
+#if __LINUX__
   if (fstat64 (fd, &st2) < 0)
+#else
+  if (fstat (fd, &st2) < 0)
+#endif
     {
       error (0, errno, "Couldn't fstat temporary file");
       goto failure;
