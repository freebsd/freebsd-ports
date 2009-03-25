--- main.c.orig	2009-03-21 21:22:52.000000000 +0100
+++ main.c	2009-03-21 21:26:02.000000000 +0100
@@ -33,6 +33,10 @@
 # ifndef __dead
 #  define __dead __attribute__((__noreturn__))
 # endif
+#elif defined(__FreeBSD__)
+# ifndef __dead
+#  define __dead __attribute__((__noreturn__))
+# endif
 #endif
 
 struct	buf {
