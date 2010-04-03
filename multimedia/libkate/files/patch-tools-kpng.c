--- tools/kpng.c.orig	2008-08-06 09:06:13.000000000 +0200
+++ tools/kpng.c	2010-03-29 09:32:32.000000000 +0200
@@ -179,13 +179,13 @@
     }
   }
 
-  png_destroy_read_struct(&png_ptr,&info_ptr,png_infopp_NULL);
+  png_destroy_read_struct(&png_ptr,&info_ptr,NULL);
   fclose(f);
 
   return 0;
 
 error:
-  if (png_ptr) png_destroy_read_struct(&png_ptr,info_ptr?&info_ptr:png_infopp_NULL,png_infopp_NULL);
+  if (png_ptr) png_destroy_read_struct(&png_ptr,info_ptr?&info_ptr:NULL,NULL);
   if (f) fclose(f);
   return -1;
 }
@@ -224,7 +224,7 @@
   if (w) *w=png_get_image_width(png_ptr,info_ptr);
   if (h) *h=png_get_image_height(png_ptr,info_ptr);
 
-  png_destroy_read_struct(&png_ptr,&info_ptr,png_infopp_NULL);
+  png_destroy_read_struct(&png_ptr,&info_ptr,NULL);
 
   /* now read the whole file as a binary blob */
   fseek(f,0,SEEK_END);
@@ -241,7 +241,7 @@
   return 0;
 
 error:
-  if (png_ptr) png_destroy_read_struct(&png_ptr,info_ptr?&info_ptr:png_infopp_NULL,png_infopp_NULL);
+  if (png_ptr) png_destroy_read_struct(&png_ptr,info_ptr?&info_ptr:NULL,NULL);
   if (f) fclose(f);
   return -1;
 }
