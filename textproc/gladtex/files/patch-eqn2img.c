--- eqn2img.c.orig	2010-07-31 17:30:20.000000000 +0200
+++ eqn2img.c	2012-05-06 15:41:55.000000000 +0200
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
 
   cmd = NEW(char, 2*strlen(basename) + 38);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
