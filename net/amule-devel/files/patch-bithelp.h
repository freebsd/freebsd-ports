--- src/utils/aLinkCreator/src/bithelp.h.orig	Sat Oct 23 04:44:33 2004
+++ src/utils/aLinkCreator/src/bithelp.h	Sat Oct 23 04:45:10 2004
@@ -21,7 +21,15 @@
 #ifndef G10_BITHELP_H
 #define G10_BITHELP_H
 
-#include <stdint.h>
+#if defined(__FreeBSD__)
+  #if __FreeBSD__ < 5
+    #include <inttypes.h>
+  #else
+    #include <stdint.h>
+  #endif
+#else
+  #include <stdint.h>
+#endif
 
 /****************
  * Rotate the 32 bit unsigned integer X by N bits left/right
