--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-12-15 02:04:09.000000000 +0100
+++ chrome/browser/password_manager/chrome_password_manager_client.cc	2017-12-24 01:39:48.763209000 +0100
@@ -67,7 +67,11 @@
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/url_constants.h"
 
 #if defined(SAFE_BROWSING_DB_LOCAL)
