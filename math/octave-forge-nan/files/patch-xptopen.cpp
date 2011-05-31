--- xptopen.cpp-orig	2011-05-27 18:23:08.000000000 -0500
+++ xptopen.cpp	2011-05-27 18:34:19.000000000 -0500
@@ -77,6 +77,14 @@
 #include <byteswap.h>
 #endif
 
+#include <sys/param.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <machine/endian.h>
+#define __BIG_ENDIAN _BIG_ENDIAN
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
+
 #ifdef _WIN32
 #define __LITTLE_ENDIAN 1234
 #define __BIG_ENDIAN 4321
