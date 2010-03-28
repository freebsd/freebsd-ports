--- modules/codec/png.c.orig	2009-12-20 18:43:39.000000000 +0100
+++ modules/codec/png.c	2010-03-28 17:09:18.000000000 +0200
@@ -155,7 +155,7 @@
     p_info = png_create_info_struct( p_png );
     if( p_info == NULL )
     {
-        png_destroy_read_struct( &p_png, png_infopp_NULL, png_infopp_NULL );
+        png_destroy_read_struct( &p_png, NULL, NULL );
         block_Release( p_block ); *pp_block = NULL;
         return NULL;
     }
@@ -163,7 +163,7 @@
     p_end_info = png_create_info_struct( p_png );
     if( p_end_info == NULL )
     {
-        png_destroy_read_struct( &p_png, &p_info, png_infopp_NULL );
+        png_destroy_read_struct( &p_png, &p_info, NULL );
         block_Release( p_block ); *pp_block = NULL;
         return NULL;
     }
