--- src/3rdparty/chromium/third_party/ffmpeg/libavutil/random_seed.c.orig	2023-09-13 13:13:30 UTC
+++ src/3rdparty/chromium/third_party/ffmpeg/libavutil/random_seed.c
@@ -35,6 +35,11 @@
 #elif CONFIG_OPENSSL
 #include <openssl/rand.h>
 #endif
+#if HAVE_ARC4RANDOM_BUF
+#undef __BSD_VISIBLE
+#define __BSD_VISIBLE 1
+#include <stdlib.h>
+#endif
 #include <fcntl.h>
 #include <math.h>
 #include <time.h>
