--- command/decoder.h.orig	2012-02-24 20:08:34 UTC
+++ command/decoder.h
@@ -18,6 +18,7 @@ extern "C"
 #include <avcodec.h>
 #else
 #include <libavcodec/avcodec.h>
+#include <libavutil/mem.h>
 #endif
 
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
