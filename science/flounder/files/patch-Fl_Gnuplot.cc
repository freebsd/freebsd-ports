--- src/Fl_Gnuplot.cc.orig	2002-12-20 03:56:35.000000000 +0900
+++ src/Fl_Gnuplot.cc	2012-10-23 23:22:44.000000000 +0900
@@ -39,11 +39,11 @@
 
 #include <stdlib.h>
 #include <stdio.h>
-#include <fstream.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <iostream>
 
 #include "FL/fl_draw.H"
 #include "FL/fl_ask.H"
@@ -53,12 +53,14 @@
 
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
