--- lib/libiax2/src/iax.c.orig	Sat Nov 12 17:29:58 2005
+++ lib/libiax2/src/iax.c	Sat Nov 12 17:31:06 2005
@@ -53,9 +53,11 @@
 #include <time.h>
 
 #ifndef MACOSX
+#ifndef __FreeBSD__
 #include <malloc.h>
 #ifndef SOLARIS
 #include <error.h>
+#endif
 #endif
 #endif
 
