--- src/bdf/bdfdrivr.c.orig	Thu Mar 18 16:44:44 2004
+++ src/bdf/bdfdrivr.c	Thu Mar 18 16:50:09 2004
@@ -315,17 +315,18 @@
 
       {
         FT_Bitmap_Size*  bsize = root->available_sizes;
+	FT_Short         resolution_x = 0, resolution_y = 0;
 
 
         FT_MEM_ZERO( bsize, sizeof ( FT_Bitmap_Size ) );
 
-        prop = bdf_get_font_property( font, "PIXEL_SIZE" );
-        if ( prop != NULL )
-          bsize->height = (FT_Short)prop->value.int32;
+	bsize->height = font->font_ascent + font->font_descent;
 
         prop = bdf_get_font_property( font, "AVERAGE_WIDTH" );
         if ( prop != NULL )
           bsize->width = (FT_Short)( ( prop->value.int32 + 5 ) / 10 );
+	else
+	  bsize->width = bsize->height * 2/3;
 
         prop = bdf_get_font_property( font, "POINT_SIZE" );
         if ( prop != NULL )
@@ -333,25 +334,29 @@
           bsize->size =
             (FT_Pos)( ( prop->value.int32 * 64 * 7200 + 36135L ) / 72270L );
 
+	prop = bdf_get_font_property( font, "PIXEL_SIZE" );
+
+	if ( prop )
+	  bsize->y_ppem = (FT_Short)prop->value.int32 << 6;
+
         prop = bdf_get_font_property( font, "RESOLUTION_X" );
-        if ( prop != NULL )
-          bsize->x_ppem =
-            (FT_Pos)( ( prop->value.int32 * bsize->size + 36 ) / 72 );
+        if ( prop )
+	  resolution_x = (FT_Short)prop->value.int32;
 
         prop = bdf_get_font_property( font, "RESOLUTION_Y" );
-        if ( prop != NULL )
-          bsize->y_ppem =
-            (FT_Pos)( ( prop->value.int32 * bsize->size + 36 ) / 72 );
-
-        if ( bsize->height == 0 )
-          bsize->height = (FT_Short)( ( bsize->y_ppem + 32 ) / 64 );
+        if ( prop )
+	  resolution_y = (FT_Short)prop->value.int32;
 
-        if ( bsize->height == 0 )
+	if ( bsize->y_ppem == 0 )
         {
-          /* some fonts have a broken SIZE declaration (jiskan24.bdf) */
-          FT_ERROR(( "BDF_Face_Init: reading size\n" ));
-          bsize->height = (FT_Short)font->point_size;
+	  bsize->y_ppem = bsize->size;
+	  if ( resolution_y )
+	    bsize->y_ppem = bsize->y_ppem * resolution_y / 72;
         }
+	if ( resolution_x && resolution_y )
+	  bsize->x_ppem = bsize->y_ppem * resolution_x / resolution_y;
+	else
+	  bsize->x_ppem = bsize->y_ppem;
       }
 
       /* encoding table */
@@ -481,13 +486,14 @@
 
 
     FT_TRACE4(( "rec %d - pres %d\n",
-                size->metrics.y_ppem, root->available_sizes->height ));
+          size->metrics.y_ppem, root->available_sizes->y_ppem ));
 
-    if ( size->metrics.y_ppem == root->available_sizes->height )
+    if ( size->metrics.y_ppem == root->available_sizes->y_ppem >> 6 )
     {
-      size->metrics.ascender    = face->bdffont->bbx.ascent << 6;
-      size->metrics.descender   = face->bdffont->bbx.descent * ( -64 );
-      size->metrics.height      = face->bdffont->bbx.height << 6;
+      size->metrics.ascender    = face->bdffont->font_ascent << 6;
+      size->metrics.descender   = -face->bdffont->font_descent << 6;
+      size->metrics.height      = ( face->bdffont->font_ascent +
+		      face->bdffont->font_descent ) << 6;
       size->metrics.max_advance = face->bdffont->bbx.width << 6;
 
       return BDF_Err_Ok;
