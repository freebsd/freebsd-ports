--- src/ffmpeg2theora.c.orig	2016-01-10 04:35:56 UTC
+++ src/ffmpeg2theora.c
@@ -3103,7 +3103,11 @@ int main(int argc, char **argv) {
                 fprintf(stderr,"\nUnable to decode input.\n");
             return(1);
         }
+#if LIBAVFORMAT_VERSION_INT < AV_VERSION_INT(53,17,0)
+        av_close_input_file(convert->context);
+#else
         avformat_close_input(&convert->context);
+#endif
     }
     else{
         if (info.frontend)
