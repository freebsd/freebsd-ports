--- ../../src/portab.h.orig	Thu May 23 04:52:08 2002
+++ ../../src/portab.h	Thu May 23 04:54:41 2002
@@ -88,7 +88,13 @@
 
 #if defined(LINUX)
 
+#include "../../../config.h"
+
+#if defined(HAVE_STDINT_H)
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 
 #define DECLARE_ALIGNED_MATRIX(name,sizex,sizey,type,alignment) \
 	type name##_storage[(sizex)*(sizey)+(alignment)-1]; \
