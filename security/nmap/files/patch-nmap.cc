--- nmap.cc.orig	2015-09-21 13:49:51 UTC
+++ nmap.cc
@@ -123,6 +123,7 @@
 
 /* $Id: nmap.cc 35268 2015-09-21 13:49:51Z dmiller $ */
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "osscan2.h"
