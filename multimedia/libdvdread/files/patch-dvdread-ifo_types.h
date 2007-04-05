--- dvdread/ifo_types.h.orig	Thu Mar  2 17:25:43 2006
+++ dvdread/ifo_types.h	Wed Apr  4 20:07:32 2007
@@ -29,7 +29,11 @@
 #endif
 #else
 #if !defined(UINT8_MAX) || !defined(UINT16_MAX) || !defined(INT32_MAX)
-#error "Must include <inttypes.h> or <stdint.h> before any libdvdread header."
+#if !defined(_SYS_STDINT_H_) || !defined(_INTTYPES_H_)
+#include <stdint.h>
+#else
+#error "UINT8_MAX, UINT16_MAX, or INT32_MAX are missing from <stdint.h> or <inttypes.h>."
+#endif
 #endif
 #endif
 
