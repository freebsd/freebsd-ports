--- ./eqn2img.c.orig	2013-03-07 15:44:58.000000000 +0100
+++ ./eqn2img.c	2013-03-07 15:47:58.000000000 +0100
@@ -367,7 +367,7 @@
   info_ptr = png_create_info_struct(png_ptr);
   assert(info_ptr);
   
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(fp);
     return NULL;
@@ -580,7 +580,7 @@
   assert(info_ptr);
 
   /* error handling, libpng longjmps here on any error */
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(fp);
     return -1;
@@ -715,7 +715,7 @@
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 46);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2> /dev/null", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
