--- zcollector.cc.orig	2015-06-25 09:16:05.655102000 +0800
+++ zcollector.cc	2015-06-25 09:16:28.606423000 +0800
@@ -5,6 +5,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "bundle.hh"
 #include "chunk_index.hh"
