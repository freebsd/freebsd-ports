--- video/global.h.orig	Tue Oct  9 15:52:30 2001
+++ video/global.h	Mon Nov  1 09:41:06 2004
@@ -32,7 +32,7 @@
 #include "quicktime.h"
 
 #include <pthread.h>
-#include <stdint.h>
+#include <inttypes.h>
 #ifdef DYNAMIC_LOADING
 #include <glib.h>
 #include <gmodule.h>
