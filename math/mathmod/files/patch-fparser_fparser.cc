--- fparser/fparser.cc.orig	2020-02-17 14:23:01 UTC
+++ fparser/fparser.cc
@@ -18,6 +18,7 @@
 #include <cmath>
 #include <cassert>
 #include <limits>
+#include <sys/types.h>
 
 #include "extrasrc/fptypes.hh"
 #include "extrasrc/fpaux.hh"
