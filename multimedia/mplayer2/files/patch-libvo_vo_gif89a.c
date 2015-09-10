--- libvo/vo_gif89a.c.orig	2013-07-09 16:33:16 UTC
+++ libvo/vo_gif89a.c
@@ -44,13 +44,13 @@
  * entire argument being interpretted as the filename.
  */
 
-#include <gif_lib.h>
-
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
+#include <gif_lib.h>
+
 #include "config.h"
 #include "subopt-helper.h"
 #include "video_out.h"
@@ -69,6 +69,15 @@ static const vo_info_t info = {
 
 const LIBVO_EXTERN(gif89a)
 
+#if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
+#define EGifOpenFileName(a, b) EGifOpenFileName(a, b, NULL)
+#define MakeMapObject GifMakeMapObject
+#define FreeMapObject GifFreeMapObject
+#define QuantizeBuffer GifQuantizeBuffer
+#if defined GIFLIB_MINOR && GIFLIB_MINOR >= 1
+#define EGifCloseFile(a) EGifCloseFile(a, NULL)
+#endif
+#endif
 
 // how many frames per second we are aiming for during output.
 static float target_fps;
@@ -92,6 +101,8 @@ static uint32_t img_width;
 static uint32_t img_height;
 // image data for slice rendering
 static uint8_t *slice_data = NULL;
+// pointer for whole frame rendering
+static uint8_t *frame_data = NULL;
 // reduced image data for flip_page
 static uint8_t *reduce_data = NULL;
 // reduced color map for flip_page
@@ -156,7 +167,7 @@ static int config(uint32_t s_width, uint
 		uint32_t d_height, uint32_t flags, char *title,
 		uint32_t format)
 {
-#ifdef CONFIG_GIF_4
+#if defined CONFIG_GIF_4 || GIFLIB_MAJOR >= 5
 	// these are control blocks for the gif looping extension.
 	char LB1[] = "NETSCAPE2.0";
 	char LB2[] = { 1, 0, 0 };
@@ -185,23 +196,25 @@ static int config(uint32_t s_width, uint
 		return 1;
 	}
 
+	new_gif = EGifOpenFileName(gif_filename, 0);
+	if (new_gif == NULL) {
+		mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: error opening file \"%s\" for output.\n", gif_filename);
+		return 1;
+	}
+
+#if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
+	EGifSetGifVersion(new_gif, 1);
+#elif defined CONFIG_GIF_4
 	// the EGifSetGifVersion line causes segfaults in certain
 	// earlier versions of libungif.  i don't know exactly which,
 	// but certainly in all those before v4.  if you have problems,
 	// you need to upgrade your gif library.
-#ifdef CONFIG_GIF_4
 	EGifSetGifVersion("89a");
 #else
 	mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: Your version of libungif needs to be upgraded.\n");
 	mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: Some functionality has been disabled.\n");
 #endif
 
-	new_gif = EGifOpenFileName(gif_filename, 0);
-	if (new_gif == NULL) {
-		mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: error opening file \"%s\" for output.\n", gif_filename);
-		return 1;
-	}
-
 	slice_data = malloc(img_width * img_height * 3);
 	if (slice_data == NULL) {
 		mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: malloc failed.\n");
@@ -231,7 +244,12 @@ static int config(uint32_t s_width, uint

 	// set the initial width and height info.
 	EGifPutScreenDesc(new_gif, s_width, s_height, 256, 0, reduce_cmap);
-#ifdef CONFIG_GIF_4
+#if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
+	EGifPutExtensionLeader(new_gif, 0xFF);
+	EGifPutExtensionBlock(new_gif, 11, LB1);
+	EGifPutExtensionBlock(new_gif, 3, LB2);
+	EGifPutExtensionTrailer(new_gif);
+#elif defined CONFIG_GIF_4
 	// version 3 of libungif does not support multiple control blocks.
 	// looping requires multiple control blocks.
 	// therefore, looping is only enabled for v4 and up.
@@ -311,7 +329,8 @@ static void flip_page(void)
 
 static int draw_frame(uint8_t *src[])
 {
-	return 1;
+	frame_data = src[0];
+	return 0;
 }
 
 static int draw_slice(uint8_t *src[], int stride[], int w, int h, int x, int y)
@@ -370,6 +389,7 @@ static void uninit(void)
 	// set the pointers back to null.
 	new_gif = NULL;
 	gif_filename = NULL;
+	frame_data = NULL;
 	slice_data = NULL;
 	reduce_data = NULL;
	reduce_cmap = NULL;
