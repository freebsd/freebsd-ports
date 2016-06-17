--- contrib/lips4/gdevlips.h.orig	2015-03-30 08:21:24 UTC
+++ contrib/lips4/gdevlips.h
@@ -191,6 +191,14 @@
     bool faceup;\
     char mediaType[LIPS_MEDIACHAR_MAX]
 
+/* added by shige 11/06 2003 */
+#define USE_LIPS_SIZE_ERROR
+#define LIPS_SIZE_ERROR_VALUE	2
+
+/* added by shige 11/09 2003 */
+#define LIPS_HEIGHT_MAX_720 11906
+#define LIPS_WIDTH_MAX_720 8419
+
 int lips_media_selection(int width, int height);
 int lips_packbits_encode(byte * inBuff, byte * outBuff, int Length);
 int lips_mode3format_encode(byte * inBuff, byte * outBuff, int Length);
