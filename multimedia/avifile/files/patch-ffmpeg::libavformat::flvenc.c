--- ffmpeg/libavformat/flvenc.c.orig	Wed Nov 19 10:06:53 2003
+++ ffmpeg/libavformat/flvenc.c	Wed Nov 19 10:08:10 2003
@@ -226,11 +226,12 @@
 {
     ByteIOContext *pb = &s->pb;
     FLVContext *flv = s->priv_data;
-
+    int64_t file_size;
+    int flags = 0;
+    
     Dump(flv,pb,1);
 
-    int64_t file_size = url_ftell(pb);
-    int flags = 0;
+    file_size = url_ftell(pb);
     flags |= flv->hasAudio ? 4 : 0;
     flags |= flv->hasVideo ? 1 : 0;
     url_fseek(pb, 4, SEEK_SET);
