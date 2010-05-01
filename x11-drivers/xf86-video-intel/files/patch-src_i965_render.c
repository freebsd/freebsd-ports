--- src/i965_render.c.orig	2009-05-12 19:12:11.000000000 -0500
+++ src/i965_render.c	2010-03-07 15:30:45.000000000 -0600
@@ -181,26 +181,8 @@
     return TRUE;
 }
 
-static Bool i965_check_composite_texture(PicturePtr pPict, int unit)
+static Bool i965_check_composite_texture(ScrnInfoPtr pScrn, PicturePtr pPict, int unit)
 {
-    ScrnInfoPtr pScrn = xf86Screens[pPict->pDrawable->pScreen->myNum];
-    int w = pPict->pDrawable->width;
-    int h = pPict->pDrawable->height;
-    int i;
-
-    if ((w > 8192) || (h > 8192))
-        I830FALLBACK("Picture w/h too large (%dx%d)\n", w, h);
-
-    for (i = 0; i < sizeof(i965_tex_formats) / sizeof(i965_tex_formats[0]);
-	 i++)
-    {
-        if (i965_tex_formats[i].fmt == pPict->format)
-            break;
-    }
-    if (i == sizeof(i965_tex_formats) / sizeof(i965_tex_formats[0]))
-        I830FALLBACK("Unsupported picture format 0x%x\n",
-		     (int)pPict->format);
-
     if (pPict->repeatType > RepeatReflect)
 	I830FALLBACK("extended repeat (%d) not supported\n",
 		     pPict->repeatType);
@@ -211,6 +193,26 @@
         I830FALLBACK("Unsupported filter 0x%x\n", pPict->filter);
     }
 
+    if (pPict->pDrawable)
+    {
+	int w, h, i;
+
+	w = pPict->pDrawable->width;
+	h = pPict->pDrawable->height;
+	if ((w > 8192) || (h > 8192))
+	    I830FALLBACK("Picture w/h too large (%dx%d)\n", w, h);
+
+	for (i = 0; i < sizeof(i965_tex_formats) / sizeof(i965_tex_formats[0]);
+	     i++)
+	{
+	    if (i965_tex_formats[i].fmt == pPict->format)
+		break;
+	}
+	if (i == sizeof(i965_tex_formats) / sizeof(i965_tex_formats[0]))
+	    I830FALLBACK("Unsupported picture format 0x%x\n",
+			 (int)pPict->format);
+    }
+
     return TRUE;
 }
 
@@ -239,9 +241,9 @@
 	}
     } 
 
-    if (!i965_check_composite_texture(pSrcPicture, 0))
+    if (!i965_check_composite_texture(pScrn, pSrcPicture, 0))
         I830FALLBACK("Check Src picture texture\n");
-    if (pMaskPicture != NULL && !i965_check_composite_texture(pMaskPicture, 1))
+    if (pMaskPicture != NULL && !i965_check_composite_texture(pScrn, pMaskPicture, 1))
         I830FALLBACK("Check Mask picture texture\n");
 
     if (!i965_get_dest_format(pDstPicture, &tmp1))
@@ -1258,7 +1260,7 @@
 		       PicturePtr pMaskPicture, PicturePtr pDstPicture,
 		       PixmapPtr pSrc, PixmapPtr pMask, PixmapPtr pDst)
 {
-    ScrnInfoPtr pScrn = xf86Screens[pSrcPicture->pDrawable->pScreen->myNum];
+    ScrnInfoPtr pScrn = xf86Screens[pDstPicture->pDrawable->pScreen->myNum];
     I830Ptr pI830 = I830PTR(pScrn);
     struct gen4_render_state *render_state= pI830->gen4_render_state;
     gen4_composite_op *composite_op = &render_state->composite_op;
