--- xftfreetype.c	2003/04/17 04:29:24	1.31
+++ xftfreetype.c	2003/04/24 16:14:58	1.32
@@ -638,6 +638,7 @@
     int			alloc_size;
     int			ascent, descent, height;
     int			i;
+    int			num_glyphs;
 
     if (!info)
 	return 0;
@@ -769,8 +770,13 @@
 	rehash_value = 0;
     }
     
+    /*
+     * Sometimes the glyphs are numbered 1..n, other times 0..n-1,
+     * accept either numbering scheme by making room in the table
+     */
+    num_glyphs = face->num_glyphs + 1;
     alloc_size = (sizeof (XftFontInt) + 
-		  face->num_glyphs * sizeof (XftGlyph *) +
+		  num_glyphs * sizeof (XftGlyph *) +
 		  hash_value * sizeof (XftUcsHash));
     font = malloc (alloc_size);
     
@@ -867,8 +873,8 @@
      * Per glyph information
      */
     font->glyphs = (XftGlyph **) (font + 1);
-    memset (font->glyphs, '\0', face->num_glyphs * sizeof (XftGlyph *));
-    font->num_glyphs = face->num_glyphs;
+    memset (font->glyphs, '\0', num_glyphs * sizeof (XftGlyph *));
+    font->num_glyphs = num_glyphs;
     /*
      * Unicode hash table information
      */
