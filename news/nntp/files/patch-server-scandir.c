--- server/scandir.c.orig	Sat Nov  5 07:04:53 1994
+++ server/scandir.c	Mon Nov  4 05:44:47 2002
@@ -21,7 +21,9 @@
  */
 
 extern	int	intcmp();
+#ifndef __FreeBSD__
 extern char *malloc(), *realloc();
+#endif
 
 int
 scan_dir(low_msg, high_msg)
