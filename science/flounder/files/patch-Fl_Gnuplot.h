--- src/Fl_Gnuplot.h.orig	Tue Oct 15 04:00:20 2002
+++ src/Fl_Gnuplot.h	Tue Oct 15 04:00:37 2002
@@ -47,6 +47,8 @@
 #include "FL/Fl_Widget.H"
 #include "FL/Fl_Box.H"
 
+using namespace std;
+
 class Fl_Gnuplot : public Fl_Box {
 private:
   Fl_Gnuplot();
