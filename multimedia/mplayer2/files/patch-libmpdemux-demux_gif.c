--- libmpdemux/demux_gif.c.orig	2013-07-09 16:33:16 UTC
+++ libmpdemux/demux_gif.c
@@ -44,6 +44,16 @@ typedef struct {
 
 #define GIF_SIGNATURE (('G' << 16) | ('I' << 8) | 'F')
 
+static void PrintGifError(void)
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
