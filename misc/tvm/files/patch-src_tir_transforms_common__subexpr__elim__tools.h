--- src/tir/transforms/common_subexpr_elim_tools.h.orig	2022-07-21 17:19:38 UTC
+++ src/tir/transforms/common_subexpr_elim_tools.h
@@ -37,7 +37,7 @@
 #include <utility>        // For pairs datatype
 #include <vector>
 
-#include "../../../3rdparty/dmlc-core/include/dmlc/optional.h"
+#include <dmlc/optional.h>
 
 namespace tvm {
 namespace tir {
