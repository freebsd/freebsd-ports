
$FreeBSD$

--- src/test.c.orig	Tue Feb  4 00:43:33 2003
+++ src/test.c	Tue Feb  4 00:43:50 2003
@@ -153,6 +153,7 @@
   return (stat (path, finfo));
 }
 
+#define eaccess test_access
 /* Do the same thing access(2) does, but use the effective uid and gid,
    and don't make the mistake of telling root that any file is executable.
    But this loses when the containing filesystem is mounted e.g. read-only.  */
