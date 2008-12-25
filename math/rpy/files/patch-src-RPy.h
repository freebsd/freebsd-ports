--- src/RPy.h.orig	2008-12-17 16:53:19.000000000 +0800
+++ src/RPy.h	2008-12-17 16:53:35.000000000 +0800
@@ -74,7 +74,7 @@
 #  endif
 #endif  /* _WIN32 */
 
-#include <Rdevices.h> /* must follow Graphics.h */
+#include <Rembedded.h> /* must follow Graphics.h */
 
 
 /* Missing definitions from Rinterface.h or RStartup.h */
