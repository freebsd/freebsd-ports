--- third_party/WebKit/Source/WebCore/config.h.orig	2012-05-30 10:05:35.000000000 +0300
+++ third_party/WebKit/Source/WebCore/config.h	2012-06-05 22:32:48.000000000 +0300
@@ -127,6 +127,14 @@
 #define WTF_USE_NEW_THEME 1
 #endif // PLATFORM(MAC)
 
+#if OS(FREEBSD)
+#include <sys/param.h>
+#if __FreeBSD_version < 802502
+#define log2(x) (log(x) / M_LN2)
+#define log2f(x) (logf(x) / (float)M_LN2)
+#endif
+#endif
+
 #if PLATFORM(CHROMIUM)
 
 // Chromium uses this file instead of JavaScriptCore/config.h to compile
