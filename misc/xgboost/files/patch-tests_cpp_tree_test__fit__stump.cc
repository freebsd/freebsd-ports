-- correct paths of header files

--- tests/cpp/tree/test_fit_stump.cc.orig	2026-09-15 08:12:47 UTC
+++ tests/cpp/tree/test_fit_stump.cc
@@ -4,8 +4,8 @@
 #include <gtest/gtest.h>
 #include <xgboost/linalg.h>
 
-#include "../../src/common/linalg_op.h"
-#include "../../src/tree/fit_stump.h"
+#include "../../../src/common/linalg_op.h"
+#include "../../../src/tree/fit_stump.h"
 #include "../collective/test_worker.h"  // for TestDistributedGlobal
 #include "../helpers.h"
 
