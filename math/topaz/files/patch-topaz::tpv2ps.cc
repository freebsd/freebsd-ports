--- topaz/tpv2ps.cc.orig	Fri Jun 27 14:35:40 2003
+++ topaz/tpv2ps.cc	Thu Jul 24 02:50:11 2003
@@ -31,8 +31,6 @@
 #include <math.h>
 #include <string>
 #include <time.h>
-#include <getopt.h>
-//char *optarg;
 
 extern int errno;
 #include "vectdefs.h"
@@ -63,31 +61,31 @@
 
 #define buffersize 1024
 
-char* entry[] = {
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
+static const char *entry[] = {
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
 
-char* kentry[] = {
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"Ryumin-Light-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
-  {"GothicBBB-Medium-H"},
+static const char *kentry[] = {
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
