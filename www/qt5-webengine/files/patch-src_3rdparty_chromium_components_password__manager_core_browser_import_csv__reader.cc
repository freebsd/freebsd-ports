--- src/3rdparty/chromium/components/password_manager/core/browser/import/csv_reader.cc.orig	2017-01-26 00:49:12 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/import/csv_reader.cc
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
 
