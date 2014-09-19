--- libmpdemux/demuxer.h.orig	2014-09-19 05:04:22.000000000 +0200
+++ libmpdemux/demuxer.h	2014-09-19 05:01:57.000000000 +0200
@@ -121,7 +121,7 @@
 #define SEEK_BACKWARD (1 << 3)
 
 // demux_lavf can pass lavf buffers using FF_INPUT_BUFFER_PADDING_SIZE instead
-#define MP_INPUT_BUFFER_PADDING_SIZE 16
+#define MP_INPUT_BUFFER_PADDING_SIZE 32
 
 typedef struct demux_stream {
     int buffer_pos;        // current buffer position
