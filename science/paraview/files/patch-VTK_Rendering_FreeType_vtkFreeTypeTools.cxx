--- VTK/Rendering/FreeType/vtkFreeTypeTools.cxx.orig	2014-01-11 15:02:09.000000000 +0100
+++ VTK/Rendering/FreeType/vtkFreeTypeTools.cxx	2015-01-29 21:09:32.000000000 +0100
@@ -1186,8 +1186,10 @@
     if (bitmap)
       {
       metaData.ascent = std::max(bitmapGlyph->top - 1, metaData.ascent);
-      metaData.descent = std::min(-(bitmap->rows - (bitmapGlyph->top - 1)),
-                                  metaData.descent);
+//      metaData.descent = std::min(-(bitmap->rows - (bitmapGlyph->top - 1)),
+//                                  metaData.descent);
+      metaData.descent = std::min(-(static_cast<int>(bitmap->rows) - (bitmapGlyph->top - 1)),
+                                    metaData.descent);
       }
     ++heightString;
     }
@@ -1951,8 +1953,8 @@
     if (bitmap)
       {
       bbox[0] = std::min(bbox[0], pen[0] + bitmapGlyph->left);
-      bbox[1] = std::max(bbox[1], pen[0] + bitmapGlyph->left + bitmap->width);
-      bbox[2] = std::min(bbox[2], pen[1] + bitmapGlyph->top - 1 - bitmap->rows);
+      bbox[1] = std::max(bbox[1], pen[0] + bitmapGlyph->left + static_cast<int>(bitmap->width));
+      bbox[2] = std::min(bbox[2], pen[1] + bitmapGlyph->top - 1 - static_cast<int>(bitmap->rows));
       bbox[3] = std::max(bbox[3], pen[1] + bitmapGlyph->top - 1);
       }
     else
