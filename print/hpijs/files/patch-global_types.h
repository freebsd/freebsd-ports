--- global_types.h.orig	Thu Sep  5 08:27:18 2002
+++ global_types.h	Wed Sep 11 02:05:22 2002
@@ -46,10 +46,14 @@
 #include "models.h"
 #include "modes.h"
 
+#if HAVE_INTTYPES_H
+    #include <inttypes.h>
+#else
 #if HAVE_STDINT_H
     #include <stdint.h>
 #else
     typedef unsigned long uint32_t;
+#endif
 #endif
 
 // ** Defines
