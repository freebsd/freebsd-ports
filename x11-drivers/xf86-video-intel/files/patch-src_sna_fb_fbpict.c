--- src/sna/fb/fbpict.c.orig	2013-03-27 11:58:09 UTC
+++ src/sna/fb/fbpict.c
@@ -156,6 +156,16 @@ create_conical_gradient_image(PictGradie
 						    gradient->nstops);
 }
 
+static inline bool
+picture_has_clip(PicturePtr p)
+{
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(1,16,99,1,0)
+	return p->clientClip;
+#else
+	return p->clientClipType != CT_NONE;
+#endif
+}
+
 static pixman_image_t *
 create_bits_picture(PicturePtr pict, Bool has_clip, int *xoff, int *yoff)
 {
@@ -180,7 +190,7 @@ create_bits_picture(PicturePtr pict, Boo
 	 * only set the clip region for pictures with drawables
 	 */
 	if (has_clip) {
-		if (pict->clientClipType != CT_NONE)
+		if (picture_has_clip(pict))
 			pixman_image_set_has_client_clip(image, TRUE);
 
 		if (*xoff || *yoff)
