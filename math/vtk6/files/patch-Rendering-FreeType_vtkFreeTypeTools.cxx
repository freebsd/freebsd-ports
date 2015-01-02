--- Rendering/FreeType/vtkFreeTypeTools.cxx.orig	2015-01-02 17:05:19.000000000 +0000
+++ Rendering/FreeType/vtkFreeTypeTools.cxx	2015-01-02 17:05:26.000000000 +0000
@@ -1185,8 +1185,8 @@
           bitmapGlyph);
     if (bitmap)
       {
-      metaData.ascent = std::max(bitmapGlyph->top - 1, metaData.ascent);
-      metaData.descent = std::min(-(bitmap->rows - (bitmapGlyph->top - 1)),
+      metaData.ascent = std::max<int>(bitmapGlyph->top - 1, metaData.ascent);
+      metaData.descent = std::min<int>(-(bitmap->rows - (bitmapGlyph->top - 1)),
                                   metaData.descent);
       }
     ++heightString;
@@ -1950,10 +1950,10 @@
                                         fontSize, gindex, bitmapGlyph);
     if (bitmap)
       {
-      bbox[0] = std::min(bbox[0], pen[0] + bitmapGlyph->left);
-      bbox[1] = std::max(bbox[1], pen[0] + bitmapGlyph->left + bitmap->width);
-      bbox[2] = std::min(bbox[2], pen[1] + bitmapGlyph->top - 1 - bitmap->rows);
-      bbox[3] = std::max(bbox[3], pen[1] + bitmapGlyph->top - 1);
+      bbox[0] = std::min<int>(bbox[0], pen[0] + bitmapGlyph->left);
+      bbox[1] = std::max<int>(bbox[1], pen[0] + bitmapGlyph->left + bitmap->width);
+      bbox[2] = std::min<int>(bbox[2], pen[1] + bitmapGlyph->top - 1 - bitmap->rows);
+      bbox[3] = std::max<int>(bbox[3], pen[1] + bitmapGlyph->top - 1);
       }
     else
       {
