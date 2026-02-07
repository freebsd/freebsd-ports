--- topaz/tpv2ps.cc.orig	Sun Oct 16 22:21:44 2005
+++ topaz/tpv2ps.cc	Sun Apr 23 03:11:39 2006
@@ -31,8 +31,6 @@
 #include <math.h>
 #include <string>
 #include <time.h>
-#include <getopt.h>
-//char *optarg;
 
 extern int errno;
 #include "vectdefs.h"
@@ -64,30 +62,30 @@
 #define buffersize 1024
 
 static char entry[13][100] = {
-  {"Times-Roman-Q"},
-  {"Times-Bold-Q"},
-  {"Times-Italic-Q"},
-  {"Times-BoldItalic-Q"},
-  {"Helvetica-Q"},
-  {"Helvetica-Bold-Q"},
-  {"Helvetica-Oblique-Q"},
-  {"Helvetica-BoldOblique-Q"},
-  {"Courier-Q"},
-  {"Courier-Bold-Q"},
-  {"Courier-Oblique-Q"},
-  {"Courier-BoldOblique-Q"},
-  {"Symbol"}
+  "Times-Roman-Q",
+  "Times-Bold-Q",
+  "Times-Italic-Q",
+  "Times-BoldItalic-Q",
+  "Helvetica-Q",
+  "Helvetica-Bold-Q",
+  "Helvetica-Oblique-Q",
+  "Helvetica-BoldOblique-Q",
+  "Courier-Q",
+  "Courier-Bold-Q",
+  "Courier-Oblique-Q",
+  "Courier-BoldOblique-Q",
+  "Symbol"
 };
 
 static char kentry[8][100] = {
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
+  "Ryumin-Light-H",
+  "Ryumin-Light-H",
+  "Ryumin-Light-H",
+  "Ryumin-Light-H",
+  "GothicBBB-Medium-H",
+  "GothicBBB-Medium-H",
+  "GothicBBB-Medium-H",
+  "GothicBBB-Medium-H",
 };
 
 double papery;
