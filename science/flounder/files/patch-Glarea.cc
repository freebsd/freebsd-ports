--- src/Glarea.cc.orig	Tue Oct 15 01:18:55 2002
+++ src/Glarea.cc	Tue Oct 15 01:22:10 2002
@@ -1064,7 +1064,7 @@
 
 
 // Constructor for Glarea class
-Glarea::Glarea (int X, int Y, int W, int H, const char *L=0):
+Glarea::Glarea (int X, int Y, int W, int H, const char *L):
  Fl_Gl_Window(X, Y, W, H, L)
 {
 	maxdim          = 0;
@@ -1695,7 +1695,7 @@
 }
 
 // update the tableau user interface widget
-void Glarea :: tableau( TableauUI *tb, bool update=false ) 
+void Glarea :: tableau( TableauUI *tb, bool update ) 
 {
 	if( tb->window->visible() == false ) return;
 	
@@ -1917,7 +1917,7 @@
 // set update to return the values into the vars, otherwise
 // set the variables from the supplied parameters
 void Glarea :: contours( bool& con, bool& dat, int& nc, double& st, double& inc, 
-									bool update=false )
+									bool update )
 {
 	if( update == false ) {
 		showcontour = con;
