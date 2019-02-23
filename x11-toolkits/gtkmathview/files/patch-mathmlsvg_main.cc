--- mathmlsvg/main.cc.orig	2007-08-17 10:02:46 UTC
+++ mathmlsvg/main.cc
@@ -18,6 +18,8 @@
 
 #include <config.h>
 
+#include <cstring>
+#include <unistd.h>
 #include <cassert>
 #include <fstream>
 
