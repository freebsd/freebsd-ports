--- third_party/WebKit/Source/WebCore/config.h.orig	2011-07-19 20:24:21.258582723 +0300
+++ third_party/WebKit/Source/WebCore/config.h	2011-07-19 20:25:31.840201896 +0300
@@ -199,6 +199,13 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+#if OS(FREEBSD)
+#include <sys/param.h>
+#if __FreeBSD_version < 802502
+#define log2(x) (log(x) / M_LN2)
+#endif
+#endif
+
 #if OS(UNIX) || OS(WINDOWS)
 #define WTF_USE_OS_RANDOMNESS 1
 #endif
