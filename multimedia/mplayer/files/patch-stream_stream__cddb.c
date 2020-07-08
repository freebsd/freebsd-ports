--- stream/stream_cddb.c.orig	2020-07-07 15:46:58 UTC
+++ stream/stream_cddb.c
@@ -77,7 +77,7 @@
 #include "network.h"
 #include "libavutil/common.h"
 
-#define DEFAULT_FREEDB_SERVER "freedb.freedb.org"
+#define DEFAULT_FREEDB_SERVER "gnudb.gnudb.org"
 #define DEFAULT_CACHE_DIR     "/.cddb/"
 
 typedef struct {
