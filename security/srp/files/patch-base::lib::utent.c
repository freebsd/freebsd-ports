--- base/lib/utent.c.orig	Wed Aug 15 20:50:34 2001
+++ base/lib/utent.c	Wed Aug 15 20:54:08 2001
@@ -47,6 +47,9 @@
  * setutent - open or rewind the utmp file
  */
 
+#if defined(__FreeBSD__)
+#define _UTMP_FILE _PATH_UTMP
+#endif
 void
 setutent ()
 {
