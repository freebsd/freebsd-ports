--- src/Fl_Gnuplot.cc.orig	Tue Oct 15 03:59:41 2002
+++ src/Fl_Gnuplot.cc	Tue Oct 15 04:02:05 2002
@@ -44,6 +44,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <iostream>
 
 #include "FL/fl_draw.H"
 #include "FL/fl_ask.H"
@@ -53,12 +54,14 @@
 
 #define N_ENTRIES 8192
 
+using namespace std;
+
 // enter a GNUP{LOT command to be executed 
 void gnuplotcom_cb( Fl_Widget *w, void *p )
 {
 	Fl_Gnuplot* graph=(Fl_Gnuplot*)w;
 
-	char *s=fl_input("Enter Gnuplot commands seperated by ;",graph->command() );
+	char *s=(char*)fl_input("Enter Gnuplot commands seperated by ;",graph->command() );
 	if( s != NULL ) graph->command(s);
 	graph->window()->redraw();
 }
