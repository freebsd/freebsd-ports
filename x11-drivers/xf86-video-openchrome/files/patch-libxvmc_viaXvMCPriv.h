--- libxvmc/viaXvMCPriv.h.orig	Wed Jan 25 15:56:20 2006
+++ libxvmc/viaXvMCPriv.h	Sun Nov 25 09:43:03 2007
@@ -31,2 +31,3 @@
 #include <stdlib.h>
+#include <pthread.h>		/* For FreeBSD 5.x */
 #include <X11/Xutil.h>
