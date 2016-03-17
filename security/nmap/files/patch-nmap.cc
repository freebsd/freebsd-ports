--- nmap.cc.orig	2016-03-14 23:54:51 UTC
+++ nmap.cc
@@ -123,6 +123,7 @@
 
 /* $Id: nmap.cc 35683 2016-03-14 23:54:51Z dmiller $ */
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "osscan2.h"
