--- ./routines/graphics/periPos.c.orig	Tue Mar 21 19:07:20 2006
+++ ./routines/graphics/periPos.c	Tue Mar 21 19:07:46 2006
@@ -1225,6 +1225,7 @@
 {     
   integer i,rect[4] ;
   int yn = (int) (*y + ascentPos());
+  int alloc;
 
   if ( ScilabGCPos_is_initialized == FALSE ) {
     sciprint("xinit must be called before any action \r\n");
@@ -1232,7 +1233,6 @@
   }
   
 #ifdef WITH_GTK
-  int alloc;
   /* we expect iso-latin1 in postscript */
   string = sci_convert_from_utf8(string, &alloc,NULL);
 #endif 
