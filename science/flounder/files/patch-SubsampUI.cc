--- src/SubsampUI.cc.orig	Tue Oct 15 02:14:13 2002
+++ src/SubsampUI.cc	Tue Oct 15 02:14:19 2002
@@ -28,7 +28,7 @@
 	((Strideslide *)p)->update();
 }
 
-Strideslide :: Strideslide( int X, int Y, int W, int H, char *L=0): 
+Strideslide :: Strideslide( int X, int Y, int W, int H, char *L): 
     Fl_Group(X,Y,W,H,L),
     slider( X, Y, W-w_valout-w_sep-w_samplabel, H ),
     valout(X+W-w_valout-w_samplabel,Y,w_valout, H ),
