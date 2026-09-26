--- third_party/iamf_tools/src/iamf/cli/codec/opus_utils.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_utils.cc
@@ -3,7 +3,7 @@
 #include "absl/status/status.h"
 #include "absl/strings/str_cat.h"
 #include "absl/strings/string_view.h"
-#include "include/opus_defines.h"
+#include "third_party/opus/src/include/opus_defines.h"
 
 namespace iamf_tools {
 
