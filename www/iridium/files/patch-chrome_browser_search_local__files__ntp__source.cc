--- chrome/browser/search/local_files_ntp_source.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/search/local_files_ntp_source.cc
@@ -20,8 +20,13 @@
 #include "build/build_config.h"
 #include "chrome/common/url_constants.h"
 #include "content/public/browser/url_data_source.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#include <re2/stringpiece.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
 #include "third_party/re2/src/re2/stringpiece.h"
+#endif
 
 namespace {
 
