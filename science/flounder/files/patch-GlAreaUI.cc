--- src/GlAreaUI.cc.orig	Thu Jan 16 02:49:11 2003
+++ src/GlAreaUI.cc	Thu Jan 16 02:50:08 2003
@@ -19,6 +19,7 @@
 #include "../config.h"
 #include "flguppy.h"
 #include <algorithm>
+#include <iostream>
 #ifdef HAVE_VALUES_H
 #include <values.h>
 #endif
@@ -34,6 +35,8 @@
 #include <avifile/utils.h>
 #include <avifile/fourcc.h>
 #endif
+
+using namespace std;
 
 Fl_Font fontset[] = {
 	FL_HELVETICA, FL_HELVETICA_BOLD, 
