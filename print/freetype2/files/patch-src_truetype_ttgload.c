--- src/truetype/ttgload.c.orig	Tue Feb 14 12:44:56 2006
+++ src/truetype/ttgload.c	Fri May 18 13:05:34 2007
@@ -269,7 +269,11 @@
 
     n_points = 0;
     if ( n_contours > 0 )
+    {
       n_points = cont[-1] + 1;
+      if ( n_points < 0 )
+        goto Invalid_Outline;
+    }
 
     /* note that we will add four phantom points later */
     error = FT_GLYPHLOADER_CHECK_POINTS( gloader, n_points + 4, 0 );
@@ -677,7 +681,7 @@
     FT_GlyphLoader  gloader = loader->gloader;
     FT_Error        error   = TT_Err_Ok;
     FT_Outline*     outline;
-    FT_UInt         n_points;
+    FT_Int          n_points;
 
 
     outline  = &gloader->current.outline;
@@ -704,7 +708,7 @@
       /* Deltas apply to the unscaled data. */
       FT_Vector*  deltas;
       FT_Memory   memory = loader->face->memory;
-      FT_UInt     i;
+      FT_Int      i;
 
 
       error = TT_Vary_Get_Glyph_Deltas( (TT_Face)(loader->face),
