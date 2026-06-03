--- eqn2img.c.orig	2014-02-20 19:54:58 UTC
+++ eqn2img.c
@@ -30,7 +30,7 @@ This utility is part of\n\
 
 #define USAGE "\
 This utility is part of\n\
-gladtex version 1.4.1, Copyright (C) 1999-2010 Martin G. Gulbrandsen\n\
+gladtex version 1.4.2, Copyright (C) 1999-2010 Martin G. Gulbrandsen\n\
                                  (C) 2014 Sebastian Humenda\n\
 \n\
 GladTXx comes with ABSOLUTELY NO WARRANTY. This is free software,\n\
@@ -634,19 +634,31 @@ int gif_write(png_bytepp image, char *img_name, int wi
   };
 
   if(img_name) {
+#if GIFLIB_MAJOR >= 5
+    fp = EGifOpenFileName(img_name, 0, NULL);
+#else
     fp = EGifOpenFileName(img_name, 0);
+#endif
     if(!fp)
       return -1;
   }
   else
+#if GIFLIB_MAJOR >= 5
+    fp = EGifOpenFileHandle(STDOUT_FILENO, NULL);
+#else
     fp = EGifOpenFileHandle(STDOUT_FILENO);
+#endif
 
   for(i=0; i<256; i++) {
     pal[i].Red = (i*background.red + (255-i)*foreground.red)/255;
     pal[i].Green = (i*background.green + (255-i)*foreground.green)/255;
     pal[i].Blue = (i*background.blue + (255-i)*foreground.blue)/255;
   }
+#if GIFLIB_MAJOR >= 5
+  color_map = GifMakeMapObject(256, pal);
+#else
   color_map = MakeMapObject(256, pal);
+#endif
 
   /* EGifSetGifVersion("89a"); this causes segfault (but is really required for transparency, I think) */
   EGifPutScreenDesc(fp, width, height, 256, 255, color_map);
@@ -660,7 +672,11 @@ int gif_write(png_bytepp image, char *img_name, int wi
       return -1;
   }
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  EGifCloseFile(fp, NULL);
+#else
   EGifCloseFile(fp);
+#endif
 
   return 0;
 }  
@@ -726,7 +742,7 @@ int to_ps(char *basename, int verbose) {
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 46);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
