--- third_party/skia/src/ports/SkFontHost_FreeType_common.cpp.orig	2017-06-27 15:42:02.870865000 +0200
+++ third_party/skia/src/ports/SkFontHost_FreeType_common.cpp	2017-06-27 15:55:12.348145000 +0200
@@ -395,8 +395,6 @@
     switch ( face->glyph->format ) {
         case FT_GLYPH_FORMAT_OUTLINE: {
             FT_Outline* outline = &face->glyph->outline;
-            FT_BBox     bbox;
-            FT_Bitmap   target;
 
             int dx = 0, dy = 0;
             if (fRec.fFlags & SkScalerContext::kSubpixelPositioning_Flag) {
@@ -405,36 +403,97 @@
                 // negate dy since freetype-y-goes-up and skia-y-goes-down
                 dy = -dy;
             }
-            FT_Outline_Get_CBox(outline, &bbox);
-            /*
-                what we really want to do for subpixel is
-                    offset(dx, dy)
-                    compute_bounds
-                    offset(bbox & !63)
-                but that is two calls to offset, so we do the following, which
-                achieves the same thing with only one offset call.
-            */
-            FT_Outline_Translate(outline, dx - ((bbox.xMin + dx) & ~63),
-                                          dy - ((bbox.yMin + dy) & ~63));
 
+            memset(glyph.fImage, 0, glyph.rowBytes() * glyph.fHeight);
+
             if (SkMask::kLCD16_Format == glyph.fMaskFormat) {
+                FT_Outline_Translate(outline, dx, dy);
                 FT_Error err = FT_Render_Glyph(face->glyph, doVert ? FT_RENDER_MODE_LCD_V :
                                                                      FT_RENDER_MODE_LCD);
                 if (err) {
                     SK_TRACEFTR(err, "Could not render glyph.");
-                    sk_bzero(glyph.fImage, glyph.computeImageSize());
                     return;
                 }
+
                 SkMask mask;
                 glyph.toMask(&mask);
+#ifdef SK_SHOW_TEXT_BLIT_COVERAGE
+                memset(mask.fImage, 0x80, mask.fBounds.height() * mask.fRowBytes);
+#endif
+                FT_GlyphSlotRec& ftGlyph = *face->glyph;
+
+                if (!SkIRect::Intersects(mask.fBounds,
+                                         SkIRect::MakeXYWH( ftGlyph.bitmap_left,
+                                                           -ftGlyph.bitmap_top,
+                                                            ftGlyph.bitmap.width,
+                                                            ftGlyph.bitmap.rows)))
+                {
+                    return;
+                }
+
+                // If the FT_Bitmap extent is larger, discard bits of the bitmap outside the mask.
+                // If the SkMask extent is larger, shrink mask to fit bitmap (clearing discarded).
+                unsigned char* origBuffer = ftGlyph.bitmap.buffer;
+                // First align the top left (origin).
+                if (-ftGlyph.bitmap_top < mask.fBounds.fTop) {
+                    int32_t topDiff = mask.fBounds.fTop - (-ftGlyph.bitmap_top);
+                    ftGlyph.bitmap.buffer += ftGlyph.bitmap.pitch * topDiff;
+                    ftGlyph.bitmap.rows -= topDiff;
+                    ftGlyph.bitmap_top = -mask.fBounds.fTop;
+                }
+                if (ftGlyph.bitmap_left < mask.fBounds.fLeft) {
+                    int32_t leftDiff = mask.fBounds.fLeft - ftGlyph.bitmap_left;
+                    ftGlyph.bitmap.buffer += leftDiff;
+                    ftGlyph.bitmap.width -= leftDiff;
+                    ftGlyph.bitmap_left = mask.fBounds.fLeft;
+                }
+                if (mask.fBounds.fTop < -ftGlyph.bitmap_top) {
+                    mask.fImage += mask.fRowBytes * (-ftGlyph.bitmap_top - mask.fBounds.fTop);
+                    mask.fBounds.fTop = -ftGlyph.bitmap_top;
+                }
+                if (mask.fBounds.fLeft < ftGlyph.bitmap_left) {
+                    mask.fImage += sizeof(uint16_t) * (ftGlyph.bitmap_left - mask.fBounds.fLeft);
+                    mask.fBounds.fLeft = ftGlyph.bitmap_left;
+                }
+                // Origins aligned, clean up the width and height.
+                int ftVertScale = (doVert ? 3 : 1);
+                int ftHoriScale = (doVert ? 1 : 3);
+                if (mask.fBounds.height() * ftVertScale < SkToInt(ftGlyph.bitmap.rows)) {
+                    ftGlyph.bitmap.rows = mask.fBounds.height() * ftVertScale;
+                }
+                if (mask.fBounds.width() * ftHoriScale < SkToInt(ftGlyph.bitmap.width)) {
+                    ftGlyph.bitmap.width = mask.fBounds.width() * ftHoriScale;
+                }
+                if (SkToInt(ftGlyph.bitmap.rows) < mask.fBounds.height() * ftVertScale) {
+                    mask.fBounds.fBottom = mask.fBounds.fTop + ftGlyph.bitmap.rows / ftVertScale;
+                }
+                if (SkToInt(ftGlyph.bitmap.width) < mask.fBounds.width() * ftHoriScale) {
+                    mask.fBounds.fRight = mask.fBounds.fLeft + ftGlyph.bitmap.width / ftHoriScale;
+                }
                 if (fPreBlend.isApplicable()) {
-                    copyFT2LCD16<true>(face->glyph->bitmap, mask, doBGR,
+                    copyFT2LCD16<true>(ftGlyph.bitmap, mask, doBGR,
                                        fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
                 } else {
-                    copyFT2LCD16<false>(face->glyph->bitmap, mask, doBGR,
+                    copyFT2LCD16<false>(ftGlyph.bitmap, mask, doBGR,
                                         fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
                 }
+                // Restore the buffer pointer so FreeType can properly free it.
+                ftGlyph.bitmap.buffer = origBuffer;
             } else {
+                FT_BBox     bbox;
+                FT_Bitmap   target;
+                FT_Outline_Get_CBox(outline, &bbox);
+                /*
+                    what we really want to do for subpixel is
+                        offset(dx, dy)
+                        compute_bounds
+                        offset(bbox & !63)
+                    but that is two calls to offset, so we do the following, which
+                    achieves the same thing with only one offset call.
+                */
+                FT_Outline_Translate(outline, dx - ((bbox.xMin + dx) & ~63),
+                                              dy - ((bbox.yMin + dy) & ~63));
+
                 target.width = glyph.fWidth;
                 target.rows = glyph.fHeight;
                 target.pitch = glyph.rowBytes();
@@ -442,8 +501,15 @@
                 target.pixel_mode = compute_pixel_mode( (SkMask::Format)fRec.fMaskFormat);
                 target.num_grays = 256;
 
-                memset(glyph.fImage, 0, glyph.rowBytes() * glyph.fHeight);
                 FT_Outline_Get_Bitmap(face->glyph->library, outline, &target);
+#ifdef SK_SHOW_TEXT_BLIT_COVERAGE
+                for (int y = 0; y < glyph.fHeight; ++y) {
+                    for (int x = 0; x < glyph.fWidth; ++x) {
+                        uint8_t& a = ((uint8_t*)glyph.fImage)[(glyph.rowBytes() * y) + x];
+                        a = SkTMax<uint8_t>(a, 0x20);
+                    }
+                }
+#endif
             }
         } break;
 
