--- src/GlAreaUI.cc.orig	Thu Mar 28 04:28:54 2002
+++ src/GlAreaUI.cc	Tue Oct 15 03:56:58 2002
@@ -19,6 +19,7 @@
 #include "../config.h"
 #include "flguppy.h"
 #include <algorithm>
+#include <iostream>
 #ifdef HAVE_VALUES_H
 #include <values.h>
 #endif
@@ -30,9 +31,11 @@
 #include <avifile/videoencoder.h>
 #include <avifile/avifile.h>
 #include <avifile/aviplay.h>
-#include <avifile/aviutil.h>
+#include <avifile/fourcc.h>
 #endif
 
+using namespace std;
+
 Fl_Font fontset[] = {
 	FL_HELVETICA, FL_HELVETICA_BOLD, 
 	FL_HELVETICA_ITALIC, FL_HELVETICA_BOLD_ITALIC,
@@ -164,7 +167,7 @@
 }
 
 //update the settings to reflect the current model window
-void GlAreaUI :: setcurrent( GLView *a, bool force=false )
+void GlAreaUI :: setcurrent( GLView *a, bool force )
 {
 	if( a == curr_glwin && force==false ) return;
 
@@ -435,7 +438,7 @@
 inline int square( int a ){return a*a; }
 
 // make gif images
-void GlAreaUI :: movie( bool single=false )
+void GlAreaUI :: movie( bool single )
 {
 	char *fn;
 	if( single == true )
