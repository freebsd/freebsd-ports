--- chrome/browser/search/local_files_ntp_source.cc.orig	2016-05-11 19:02:15 UTC
+++ chrome/browser/search/local_files_ntp_source.cc
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
 
