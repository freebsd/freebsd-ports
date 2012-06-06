--- libmpdemux/demux_gif.c.orig	2010-12-12 11:37:15.000000000 +0100
+++ libmpdemux/demux_gif.c	2012-06-06 16:58:52.000000000 +0200
@@ -45,6 +45,16 @@
 
 #define GIF_SIGNATURE (('G' << 16) | ('I' << 8) | 'F')
 
+static void localPrintGifError(void)
+{
+  char *Err = GifErrorString();
+
+  if (Err != NULL)
+    fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+  else
+    fprintf(stderr, "\nGIF-LIB undefined error %d.\n", GifError());
+}
+
 #ifndef CONFIG_GIF_TVT_HACK
 // not supported by certain versions of the library
 static int my_read_gif(GifFileType *gif, uint8_t *buf, int len)
@@ -94,14 +104,14 @@
 
   while (type != IMAGE_DESC_RECORD_TYPE) {
     if (DGifGetRecordType(gif, &type) == GIF_ERROR) {
-      PrintGifError();
+      localPrintGifError();
       return 0; // oops
     }
     if (type == TERMINATE_RECORD_TYPE)
       return 0; // eof
     if (type == SCREEN_DESC_RECORD_TYPE) {
       if (DGifGetScreenDesc(gif) == GIF_ERROR) {
-        PrintGifError();
+        localPrintGifError();
         return 0; // oops
       }
     }
@@ -109,7 +119,7 @@
       int code;
       unsigned char *p = NULL;
       if (DGifGetExtension(gif, &code, &p) == GIF_ERROR) {
-        PrintGifError();
+        localPrintGifError();
         return 0; // oops
       }
       if (code == 0xF9) {
@@ -138,7 +148,7 @@
 	  comments[length] = 0;
 	  printf("%s", comments);
           if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-            PrintGifError();
+            localPrintGifError();
             return 0; // oops
           }
 	}
@@ -146,7 +156,7 @@
       }
       while (p != NULL) {
         if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-          PrintGifError();
+          localPrintGifError();
           return 0; // oops
         }
       }
@@ -154,7 +164,7 @@
   }
 
   if (DGifGetImageDesc(gif) == GIF_ERROR) {
-    PrintGifError();
+    localPrintGifError();
     return 0; // oops
   }
 
@@ -167,7 +177,7 @@
     memset(dp->buffer, gif->SBackGroundColor, priv->w * priv->h);
 
   if (DGifGetLine(gif, buf, len) == GIF_ERROR) {
-    PrintGifError();
+    localPrintGifError();
     free(buf);
     return 0; // oops
   }
@@ -260,7 +270,7 @@
   gif = DGifOpen(demuxer->stream, my_read_gif);
 #endif
   if (!gif) {
-    PrintGifError();
+    localPrintGifError();
     free(priv);
     return NULL;
   }
@@ -302,7 +312,7 @@
   gif_priv_t *priv = demuxer->priv;
   if (!priv) return;
   if (priv->gif && DGifCloseFile(priv->gif) == GIF_ERROR)
-    PrintGifError();
+    localPrintGifError();
   free(priv->refimg);
   free(priv);
 }
