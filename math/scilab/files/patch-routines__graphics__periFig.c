--- ./routines/graphics/periFig.c.orig	Tue Mar 21 19:22:44 2006
+++ ./routines/graphics/periFig.c	Tue Mar 21 19:22:57 2006
@@ -1176,6 +1176,7 @@
   integer rect[4], font=-1,font_flag=2;
   integer verbose=0,Dnarg,Dvalue1[10];
   int pen_color;
+  int alloc;
 
   if ( ScilabGCXfig_is_initialized == FALSE ) {
     sciprint("xinit must be called before any action \r\n");
@@ -1183,7 +1184,6 @@
   }
 
 #ifdef WITH_GTK
-  int alloc;
   string = sci_convert_from_utf8(string, &alloc,NULL);
 #endif 
   C2F(boundingboxXfig)(string,x,y,rect,PI0,PI0,PI0,PD0,PD0,PD0,PD0);
