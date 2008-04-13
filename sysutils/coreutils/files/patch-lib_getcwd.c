--- lib/getcwd.c.orig	2008-04-11 20:06:03.000000000 +0200
+++ lib/getcwd.c	2008-04-11 20:06:29.000000000 +0200
@@ -30,6 +30,10 @@
 
 #include <fcntl.h> /* For AT_FDCWD on Solaris 9.  */
 
+#ifdef __FreeBSD__
+# undef AT_FDCWD
+#endif
+
 #ifndef __set_errno
 # define __set_errno(val) (errno = (val))
 #endif
