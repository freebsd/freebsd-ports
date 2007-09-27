--- test/input.cxx.orig	Fri Sep 21 21:59:12 2007
+++ test/input.cxx	Fri Sep 21 22:44:21 2007
@@ -26,6 +26,7 @@
 //
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <FL/Fl.H>
 #include <FL/Fl_Window.H>
 #include <FL/Fl_Input.H>
@@ -61,7 +62,7 @@
 
 void color_cb(Fl_Widget* button, void* v) {
   Fl_Color c;
-  switch ((int)v) {
+  switch ((long)v) {
   case 0: c = FL_BACKGROUND2_COLOR; break;
   case 1: c = FL_SELECTION_COLOR; break;
   default: c = FL_FOREGROUND_COLOR; break;
