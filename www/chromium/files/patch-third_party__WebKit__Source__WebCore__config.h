--- third_party/WebKit/Source/WebCore/config.h.orig	2011-11-10 16:05:10.000000000 +0200
+++ third_party/WebKit/Source/WebCore/config.h	2011-12-01 20:58:22.000000000 +0200
@@ -164,6 +164,14 @@
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
 #if OS(UNIX) || OS(WINDOWS)
 #define WTF_USE_OS_RANDOMNESS 1
 #endif
