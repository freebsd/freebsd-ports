--- components/password_manager/core/browser/import/csv_reader.cc.orig	2016-03-05 21:24:14.054528874 +0100
+++ components/password_manager/core/browser/import/csv_reader.cc	2016-03-05 21:24:28.997912844 +0100
@@ -9,7 +9,11 @@
 #include "base/logging.h"
 #include "base/macros.h"
 #include "base/strings/string_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace {
 
