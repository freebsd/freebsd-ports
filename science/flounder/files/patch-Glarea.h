--- src/Glarea.h.orig	2002-12-19 19:37:48.000000000 +0100
+++ src/Glarea.h	2011-11-17 11:21:09.000000000 +0100
@@ -29,7 +29,7 @@
 extern "C" {
 #include <gif_lib.h>
 }
-#include <FL/fl_file_chooser.H>
+#include <FL/Fl_File_Chooser.H>
 #include <FL/fl_ask.H>
 #include <FL/fl_draw.H>
 #include <FL/fl_show_colormap.H>
@@ -44,6 +44,8 @@
 #include "RenderEPS.h"	
 #include "IGBheader.h"
 
+using namespace std;
+
 typedef enum dispdim{DISP_XY, DISP_YZ, DISP_ZX, 
 								DISP_YX, DISP_ZY, DISP_XZ} DispDim; 
 typedef enum bbvalue{ BBXM, BBXP, BBYM, BBYP, BBZM, BBZP } BBvalue;
