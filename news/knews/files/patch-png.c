--- src/png.c.orig	Sat Nov 21 15:55:13 1998
+++ src/png.c	Sun Jun 17 19:58:21 2001
@@ -80,6 +80,7 @@
 {
     png_struct		p_str;
     png_info		p_info;
+    png_info *		p_info_ptr;
     Pixmap		pixmap;
     FILE *volatile	vol_fp  = NULL;
     void *volatile	vol_pic = NULL;
@@ -109,7 +110,8 @@
 	unsigned int	i, j, pass;
 
 	png_read_init(&p_str);
-	png_info_init(&p_info);
+	p_info_ptr = &p_info;
+	png_info_init_3(&p_info_ptr, sizeof(png_info));
 
 	png_init_io(&p_str, vol_fp);
 	png_read_info(&p_str, &p_info);
@@ -204,7 +206,7 @@
 	}
     }
 
-    png_read_destroy(&p_str, &p_info, NULL);
+    png_read_destroy(&p_str, &p_info_ptr, NULL);
     fclose((FILE *)vol_fp);
     XtFree((char *)vol_pic);
     XtFree((char *)vol_pal);
