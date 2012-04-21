--- src/i830_render.c.orig	2009-05-12 19:12:11.000000000 -0500
+++ src/i830_render.c	2010-03-07 15:30:45.000000000 -0600
@@ -210,26 +210,8 @@
 	(dblend << S8_DST_BLEND_FACTOR_SHIFT);
 }
 
-static Bool i830_check_composite_texture(PicturePtr pPict, int unit)
+static Bool i830_check_composite_texture(ScrnInfoPtr pScrn, PicturePtr pPict, int unit)
 {
-    ScrnInfoPtr pScrn = xf86Screens[pPict->pDrawable->pScreen->myNum];
-    int w = pPict->pDrawable->width;
-    int h = pPict->pDrawable->height;
-    int i;
-
-    if ((w > 2048) || (h > 2048))
-        I830FALLBACK("Picture w/h too large (%dx%d)\n", w, h);
-
-    for (i = 0; i < sizeof(i830_tex_formats) / sizeof(i830_tex_formats[0]);
-	 i++)
-    {
-        if (i830_tex_formats[i].fmt == pPict->format)
-            break;
-    }
-    if (i == sizeof(i830_tex_formats) / sizeof(i830_tex_formats[0]))
-        I830FALLBACK("Unsupported picture format 0x%x\n",
-		     (int)pPict->format);
-
     if (pPict->repeatType > RepeatReflect)
         I830FALLBACK("Unsupported picture repeat %d\n", pPict->repeatType);
 
@@ -239,6 +221,26 @@
         I830FALLBACK("Unsupported filter 0x%x\n", pPict->filter);
     }
 
+    if (pPict->pDrawable)
+    {
+	int w, h, i;
+
+	w = pPict->pDrawable->width;
+	h = pPict->pDrawable->height;
+	if ((w > 2048) || (h > 2048))
+	    I830FALLBACK("Picture w/h too large (%dx%d)\n", w, h);
+
+	for (i = 0; i < sizeof(i830_tex_formats) / sizeof(i830_tex_formats[0]);
+	     i++)
+	{
+	    if (i830_tex_formats[i].fmt == pPict->format)
+		break;
+	}
+	if (i == sizeof(i830_tex_formats) / sizeof(i830_tex_formats[0]))
+	    I830FALLBACK("Unsupported picture format 0x%x\n",
+			 (int)pPict->format);
+    }
+
     return TRUE;
 }
 
@@ -376,9 +378,9 @@
 			     "alpha and source value blending.\n");
     }
 
-    if (!i830_check_composite_texture(pSrcPicture, 0))
+    if (!i830_check_composite_texture(pScrn, pSrcPicture, 0))
         I830FALLBACK("Check Src picture texture\n");
-    if (pMaskPicture != NULL && !i830_check_composite_texture(pMaskPicture, 1))
+    if (pMaskPicture != NULL && !i830_check_composite_texture(pScrn, pMaskPicture, 1))
         I830FALLBACK("Check Mask picture texture\n");
 
     if (!i830_get_dest_format(pDstPicture, &tmp1))
@@ -392,7 +394,7 @@
 		       PicturePtr pMaskPicture, PicturePtr pDstPicture,
 		       PixmapPtr pSrc, PixmapPtr pMask, PixmapPtr pDst)
 {
-    ScrnInfoPtr pScrn = xf86Screens[pSrcPicture->pDrawable->pScreen->myNum];
+    ScrnInfoPtr pScrn = xf86Screens[pDstPicture->pDrawable->pScreen->myNum];
     I830Ptr pI830 = I830PTR(pScrn);
     uint32_t dst_format, dst_pitch;
     Bool is_affine_src, is_affine_mask;
