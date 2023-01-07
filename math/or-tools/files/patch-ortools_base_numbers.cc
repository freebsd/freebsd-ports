- workaround for https://github.com/google/or-tools/issues/3622

--- ortools/base/numbers.cc.orig	2023-01-07 08:24:55 UTC
+++ ortools/base/numbers.cc
@@ -23,6 +23,8 @@
 #include <memory>
 #include <string>
 
+#include <errno.h>
+
 // #include "ortools/base/logging.h"
 #include "absl/strings/ascii.h"
 #include "ortools/base/strtoint.h"
