--- lib/texpect/texpect.c.orig	2015-03-25 02:08:37.745245105 +0000
+++ lib/texpect/texpect.c	2015-03-25 02:20:43.393323073 +0000
@@ -55,10 +55,12 @@
 #include <libutil.h>
 #endif
 
-#ifdef	STREAMSPTY
+#ifdef STREAMSPTY
 #include <stropts.h>
 #endif /* STREAMPTY */
 
+#include <signal.h>
+
 #include <popt.h>
 #include <errno.h>
 #include <err.h>
