--- src/flguppy.cc.orig	Tue Oct 15 01:04:33 2002
+++ src/flguppy.cc	Tue Oct 15 01:05:24 2002
@@ -20,6 +20,8 @@
 
 #include "flguppy.h"
 
+using namespace std;
+
 inline void TableauUI::cb_window_i(Fl_Window*, void*) {
   closebutton->do_callback();
 }
@@ -322,7 +324,7 @@
 }
 class GlAreaUI;
 
-GLView::GLView(GlAreaUI *g, char *fn, void *d=NULL) {
+GLView::GLView(GlAreaUI *g, char *fn, void *d) {
   Fl_Double_Window* w;
   { Fl_Double_Window* o = window = new Fl_Double_Window(365, 355);
     w = o;
