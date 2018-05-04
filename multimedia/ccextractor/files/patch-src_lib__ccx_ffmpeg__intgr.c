--- src/lib_ccx/ffmpeg_intgr.c.orig	2017-01-23 20:33:53 UTC
+++ src/lib_ccx/ffmpeg_intgr.c
@@ -2,8 +2,7 @@
 
 #ifdef ENABLE_FFMPEG
 #include <libavformat/avformat.h>
-#include <libavfilter/avfiltergraph.h>
-#include <libavfilter/avcodec.h>
+#include <libavcodec/avcodec.h>
 #include <libavfilter/buffersink.h>
 #include <libavfilter/buffersrc.h>
 #include <libavutil/avstring.h>
