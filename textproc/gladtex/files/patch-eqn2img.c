--- eqn2img.c.orig	2013-01-27 04:17:45 UTC
+++ eqn2img.c
@@ -367,7 +367,7 @@ png_bytepp png_read(char *filename, int 
   info_ptr = png_create_info_struct(png_ptr);
   assert(info_ptr);
   
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(fp);
     return NULL;
@@ -580,7 +580,7 @@ int png_write(png_bytepp image, char *im
   assert(info_ptr);
 
   /* error handling, libpng longjmps here on any error */
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(fp);
     return -1;
@@ -623,19 +623,31 @@ int gif_write(png_bytepp image, char *im
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
@@ -715,7 +727,7 @@ int to_ps(char *basename, int verbose) {
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 46);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
