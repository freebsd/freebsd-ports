--- src/PlotWin.cc.orig	Tue Oct 15 02:09:34 2002
+++ src/PlotWin.cc	Tue Oct 15 02:10:22 2002
@@ -21,7 +21,7 @@
 #include <FL/Fl_Widget.H>
 
 // set the data to plot
-void PlotWin :: set_data( int n, double *d, int t=-1, double *xd=NULL )
+void PlotWin :: set_data( int n, double *d, int t, double *xd )
 {
 	if( n != datasize ) {
 		delete[] xv;
