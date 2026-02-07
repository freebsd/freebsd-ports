--- model-views/merge-dequantize-operators.h.orig	2020-08-13 20:56:51 UTC
+++ model-views/merge-dequantize-operators.h
@@ -4,6 +4,7 @@
 
 #include "../plugin-interface.h"
 
+#include <cassert>
 #include <memory>
 #include <vector>
 
