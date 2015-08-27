--- libmpdemux/demuxer.h.orig	2013-07-09 16:33:16 UTC
+++ libmpdemux/demuxer.h
@@ -121,7 +121,7 @@ enum timestamp_type {
 #define SEEK_BACKWARD (1 << 3)
 
 // demux_lavf can pass lavf buffers using FF_INPUT_BUFFER_PADDING_SIZE instead
-#define MP_INPUT_BUFFER_PADDING_SIZE 16
+#define MP_INPUT_BUFFER_PADDING_SIZE 32
 
 typedef struct demux_stream {
     int buffer_pos;        // current buffer position
