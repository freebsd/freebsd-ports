--- src/Fl_Split.cpp.orig	2011-11-17 15:41:17.000000000 +0100
+++ src/Fl_Split.cpp	2011-11-17 15:46:21.000000000 +0100
@@ -38,7 +38,7 @@
 
 void Fl_Split::position(int oix, int oiy, int newx, int newy) {
   Fl_Widget*const* a = array();
-  short* p = sizes();
+  int* p = sizes();
   p += 8; // skip group & resizable's saved size
   for (int i=children(); i--; p += 4) {
     Fl_Widget* o = *a++;
@@ -88,7 +88,7 @@
 	  return;
   }
 
-  short* p = sizes();
+  int* p = sizes();
   // resize this (skip the Fl_Group resize):
   Fl_Widget::resize(X,Y,W,H);
 
@@ -155,8 +155,8 @@
 		  int oldx = 0;
 		  int oldy = 0;
 		  Fl_Widget*const* a = array();
-		  short* q = sizes();
-		  short* p = q+8;
+		  int* q = sizes();
+		  int* p = q+8;
 		  //printf("cursor(%d,%d)\n", mx,my);
 		  for (int i=children(); i--; p += 4) {
 			  Fl_Widget* o = *a++;
