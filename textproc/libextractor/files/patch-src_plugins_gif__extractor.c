--- src/plugins/gif_extractor.c.orig	2013-06-21 16:00:16 UTC
+++ src/plugins/gif_extractor.c
@@ -78,7 +78,11 @@ EXTRACTOR_gif_extract_method (struct EXT
   if (gif_file == NULL || gif_error != 0)
   {
     if (gif_file != NULL)
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+      EGifCloseFile (gif_file, NULL);
+#else
       EGifCloseFile (gif_file);
+#endif
     return; /* not a GIF */
   }
 #endif
@@ -133,7 +137,11 @@ EXTRACTOR_gif_extract_method (struct EXT
 	       DGifGetExtensionNext(gif_file, &ext)) &&
 	      (NULL != ext) ) ; /* keep going */
     }
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  DGifCloseFile (gif_file, NULL);
+#else
   DGifCloseFile (gif_file);
+#endif
 }
 
 /* end of gif_extractor.c */
