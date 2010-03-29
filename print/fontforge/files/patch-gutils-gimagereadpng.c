--- gutils/gimagereadpng.c.orig	2009-02-22 18:26:06.000000000 +0100
+++ gutils/gimagereadpng.c	2010-03-29 09:15:26.000000000 +0200
@@ -220,13 +220,13 @@
     if ( (info_ptr->valid&PNG_INFO_tRNS) && info_ptr->num_trans>0 ) {
 	if ( info_ptr->color_type==PNG_COLOR_TYPE_RGB || info_ptr->color_type==PNG_COLOR_TYPE_RGB_ALPHA )
 	    base->trans = COLOR_CREATE(
-		    (info_ptr->trans_values.red>>8),
-		    (info_ptr->trans_values.green>>8),
-		    (info_ptr->trans_values.blue>>8));
+		    (info_ptr->trans_color.red>>8),
+		    (info_ptr->trans_color.green>>8),
+		    (info_ptr->trans_color.blue>>8));
 	else if ( base->image_type == it_mono )
-	    base->trans = info_ptr->trans[0];
+	    base->trans = info_ptr->trans_alpha[0];
 	else
-	    base->clut->trans_index = base->trans = info_ptr->trans[0];
+	    base->clut->trans_index = base->trans = info_ptr->trans_alpha[0];
     }
 
     row_pointers = galloc(info_ptr->height*sizeof(png_bytep));
