--- src/utils/aLinkCreator/src/md4.h.orig	Sat Oct 23 04:41:29 2004
+++ src/utils/aLinkCreator/src/md4.h	Sat Oct 23 04:42:03 2004
@@ -54,7 +54,15 @@
     #include "wx/wx.h"
 #endif
 
-#include <stdint.h> // needed for uint32_t
+#if defined(__FreeBSD__)
+  #if __FreeBSD__ < 5
+    #include <inttypes.h>
+  #else
+    #include <stdint.h>
+  #endif
+#else
+  #include <stdint.h> // needed for uint32_t
+#endif
 
 // Use wxString implementation or not
 //#define WANT_STRING_IMPLEMENTATION 1
