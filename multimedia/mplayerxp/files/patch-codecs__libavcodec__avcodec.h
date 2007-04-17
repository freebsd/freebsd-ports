--- codecs/libavcodec/avcodec.h.orig	Tue Apr  3 15:53:38 2007
+++ codecs/libavcodec/avcodec.h	Sun Apr 15 03:53:55 2007
@@ -34,6 +34,12 @@
 #include "avutil.h"
 #include <sys/types.h> /* size_t */
 
+#ifndef INT64_C
+#ifdef i386
+#define INT64_C(c) (c ## LL)
+#endif
+#endif
+
 #define AV_STRINGIFY(s)         AV_TOSTRING(s)
 #define AV_TOSTRING(s) #s
 
