--- src/Myslider.cc.orig	Tue Oct 15 02:08:12 2002
+++ src/Myslider.cc	Tue Oct 15 02:08:22 2002
@@ -21,7 +21,7 @@
 
 const int w_valout = 40;
 
-Myslider :: Myslider( int X, int Y, int W, int H, char *L=0): 
+Myslider :: Myslider( int X, int Y, int W, int H, char *L): 
 	Fl_Group(X,Y,W,H,L),
 	valout(X,Y,w_valout,H),
 	slider( X+w_valout, Y, W-w_valout, H )
