--- libmpdemux/demux_gif.c.orig	2013-07-09 16:33:16 UTC
+++ libmpdemux/demux_gif.c
@@ -93,14 +93,14 @@ static int demux_gif_fill_buffer(demuxer
 
   while (type != IMAGE_DESC_RECORD_TYPE) {
     if (DGifGetRecordType(gif, &type) == GIF_ERROR) {
-      PrintGifError();
+      printf("%s\n", GifErrorString(GIF_ERROR));	
       return 0; // oops
     }
     if (type == TERMINATE_RECORD_TYPE)
       return 0; // eof
     if (type == SCREEN_DESC_RECORD_TYPE) {
       if (DGifGetScreenDesc(gif) == GIF_ERROR) {
-        PrintGifError();
+        printf("%s\n", GifErrorString(GIF_ERROR));
         return 0; // oops
       }
     }
@@ -108,7 +108,7 @@ static int demux_gif_fill_buffer(demuxer
       int code;
       unsigned char *p = NULL;
       if (DGifGetExtension(gif, &code, &p) == GIF_ERROR) {
-        PrintGifError();
+        printf("%s\n", GifErrorString(GIF_ERROR));
         return 0; // oops
       }
       if (code == 0xF9) {
@@ -137,7 +137,7 @@ static int demux_gif_fill_buffer(demuxer
 	  comments[length] = 0;
 	  printf("%s", comments);
           if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-            PrintGifError();
+            printf("%s\n", GifErrorString(GIF_ERROR));
             return 0; // oops
           }
 	}
@@ -145,7 +145,7 @@ static int demux_gif_fill_buffer(demuxer
       }
       while (p != NULL) {
         if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-          PrintGifError();
+          printf("%s\n", GifErrorString(GIF_ERROR));
           return 0; // oops
         }
       }
@@ -153,7 +153,7 @@ static int demux_gif_fill_buffer(demuxer
   }
 
   if (DGifGetImageDesc(gif) == GIF_ERROR) {
-    PrintGifError();
+    printf("%s\n", GifErrorString(GIF_ERROR));
     return 0; // oops
   }
 
@@ -166,7 +166,7 @@ static int demux_gif_fill_buffer(demuxer
     memset(dp->buffer, gif->SBackGroundColor, priv->w * priv->h);
 
   if (DGifGetLine(gif, buf, len) == GIF_ERROR) {
-    PrintGifError();
+    printf("%s\n", GifErrorString(GIF_ERROR));
     free(buf);
     return 0; // oops
   }
@@ -256,10 +256,10 @@ static demuxer_t* demux_open_gif(demuxer
   lseek(demuxer->stream->fd, 0, SEEK_SET);
   gif = DGifOpenFileHandle(demuxer->stream->fd);
 #else
-  gif = DGifOpen(demuxer->stream, my_read_gif);
+  gif = DGifOpen(demuxer->stream, my_read_gif, NULL);
 #endif
   if (!gif) {
-    PrintGifError();
+    printf("%s\n", GifErrorString(GIF_ERROR));
     free(priv);
     return NULL;
   }
@@ -301,7 +301,7 @@ static void demux_close_gif(demuxer_t* d
   gif_priv_t *priv = demuxer->priv;
   if (!priv) return;
   if (priv->gif && DGifCloseFile(priv->gif) == GIF_ERROR)
-    PrintGifError();
+    printf("%s\n", GifErrorString(GIF_ERROR));
   free(priv->refimg);
   free(priv);
 }
