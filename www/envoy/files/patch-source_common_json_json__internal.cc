--- source/common/json/json_internal.cc.orig	2023-04-27 12:00:08 UTC
+++ source/common/json/json_internal.cc
@@ -15,8 +15,7 @@
 #include "source/common/common/utility.h"
 #include "source/common/protobuf/utility.h"
 
-// Do not let nlohmann/json leak outside of this file.
-#include "include/nlohmann/json.hpp"
+#include <nlohmann/json.hpp>
 
 #include "absl/strings/match.h"
 
