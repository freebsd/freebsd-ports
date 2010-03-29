--- gutils/gimagewritepng.c.orig	2009-02-22 18:26:06.000000000 +0100
+++ gutils/gimagewritepng.c	2010-03-29 09:59:24.000000000 +0200
@@ -183,8 +183,8 @@
        if ( info_ptr->num_palette<=16 )
 	   _png_set_packing(png_ptr);
        if ( base->trans!=-1 ) {
-	   info_ptr->trans = galloc(1);
-	   info_ptr->trans[0] = base->trans;
+	   info_ptr->trans_alpha = galloc(1);
+	   info_ptr->trans_alpha[0] = base->trans;
        }
    } else {
        info_ptr->color_type = PNG_COLOR_TYPE_RGB;
@@ -192,9 +192,9 @@
 	   info_ptr->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
 
        if ( base->trans!=-1 ) {
-	   info_ptr->trans_values.red = COLOR_RED(base->trans);
-	   info_ptr->trans_values.green = COLOR_GREEN(base->trans);
-	   info_ptr->trans_values.blue = COLOR_BLUE(base->trans);
+	   info_ptr->trans_color.red = COLOR_RED(base->trans);
+	   info_ptr->trans_color.green = COLOR_GREEN(base->trans);
+	   info_ptr->trans_color.blue = COLOR_BLUE(base->trans);
        }
    }
    _png_write_info(png_ptr, info_ptr);
@@ -210,7 +210,7 @@
 
     _png_write_end(png_ptr, info_ptr);
 
-    if ( info_ptr->trans!=NULL ) gfree(info_ptr->trans);
+    if ( info_ptr->trans_alpha!=NULL ) gfree(info_ptr->trans_alpha);
     if ( info_ptr->palette!=NULL ) gfree(info_ptr->palette);
     _png_destroy_write_struct(&png_ptr, &info_ptr);
     gfree(rows);
@@ -314,15 +314,15 @@
        if ( info_ptr->num_palette<=16 )
 	   png_set_packing(png_ptr);
        if ( base->trans!=-1 ) {
-	   info_ptr->trans = galloc(1);
-	   info_ptr->trans[0] = base->trans;
+	   info_ptr->trans_alpha = galloc(1);
+	   info_ptr->trans_alpha[0] = base->trans;
        }
    } else {
        info_ptr->color_type = PNG_COLOR_TYPE_RGB;
        if ( base->trans!=-1 ) {
-	   info_ptr->trans_values.red = COLOR_RED(base->trans);
-	   info_ptr->trans_values.green = COLOR_GREEN(base->trans);
-	   info_ptr->trans_values.blue = COLOR_BLUE(base->trans);
+	   info_ptr->trans_color.red = COLOR_RED(base->trans);
+	   info_ptr->trans_color.green = COLOR_GREEN(base->trans);
+	   info_ptr->trans_color.blue = COLOR_BLUE(base->trans);
        }
    }
    png_write_info(png_ptr, info_ptr);
@@ -338,7 +338,7 @@
 
     png_write_end(png_ptr, info_ptr);
 
-    if ( info_ptr->trans!=NULL ) gfree(info_ptr->trans);
+    if ( info_ptr->trans_alpha!=NULL ) gfree(info_ptr->trans_alpha);
     if ( info_ptr->palette!=NULL ) gfree(info_ptr->palette);
     png_destroy_write_struct(&png_ptr, &info_ptr);
     gfree(rows);
