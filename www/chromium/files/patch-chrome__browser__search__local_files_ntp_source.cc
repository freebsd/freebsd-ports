--- chrome/browser/search/local_files_ntp_source.cc.orig	2016-03-05 21:06:47.216601080 +0100
+++ chrome/browser/search/local_files_ntp_source.cc	2016-03-05 21:07:16.040598823 +0100
@@ -19,8 +19,13 @@
 #include "chrome/common/url_constants.h"
 #include "content/public/browser/browser_thread.h"
 #include "content/public/browser/url_data_source.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#include <re2/stringpiece.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
 #include "third_party/re2/src/re2/stringpiece.h"
+#endif
 
 namespace {
 
