--- nmap.cc.orig	2017-07-31 16:56:48 UTC
+++ nmap.cc
@@ -130,6 +130,7 @@
 
 /* $Id: nmap.cc 36896 2017-07-31 16:56:48Z dmiller $ */
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
