--- mathmlps/main.cc.orig	2007-08-17 10:02:46 UTC
+++ mathmlps/main.cc
@@ -18,7 +18,9 @@
 
 #include <config.h>
 
+#include <unistd.h>
 #include <cassert>
+#include <cstring>
 #include <fstream>
 
 #include <popt.h>
