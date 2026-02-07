--- png_img.c.orig	2017-01-16 17:36:29 UTC
+++ png_img.c
@@ -19,6 +19,7 @@
 #include <GL/gl.h>
 
 #include <png.h>
+#include <zlib.h>
 
 #include "clib/str_utils.h"
 #include "clib/dynstring.h"
@@ -69,7 +70,7 @@ pngi_first_plot (void)
   info_ptr = png_create_info_struct (png_ptr);
   if (info_ptr == NULL)
     yyerror ("png_img: could not create PNG info structure");
-  if (setjmp (png_ptr->jmpbuf)) yyerror ("png_img: could not setjmp");
+  if (setjmp (png_jmpbuf(png_ptr))) yyerror ("png_img: could not setjmp");
 
   png_init_io (png_ptr, outfile);
   png_set_compression_level (png_ptr, compression_level);
