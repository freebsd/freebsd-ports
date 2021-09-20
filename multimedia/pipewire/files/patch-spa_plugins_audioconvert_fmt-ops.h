--- spa/plugins/audioconvert/fmt-ops.h.orig	2021-09-16 13:08:56 UTC
+++ spa/plugins/audioconvert/fmt-ops.h
@@ -23,7 +23,13 @@
  */
 
 #include <math.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#else
 #include <byteswap.h>
+#endif
 
 #include <spa/utils/defs.h>
 
