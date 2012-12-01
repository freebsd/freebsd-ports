--- src/ffmpeg2theora.c.orig	2012-01-29 17:00:19.000000000 +0900
+++ src/ffmpeg2theora.c	2012-07-04 01:49:09.000000000 +0900
@@ -2970,7 +2970,11 @@
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
