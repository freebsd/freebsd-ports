--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-09-05 21:05:13.000000000 +0200
+++ chrome/browser/password_manager/chrome_password_manager_client.cc	2017-09-06 18:27:33.975903000 +0200
@@ -67,7 +67,11 @@
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if defined(SAFE_BROWSING_DB_LOCAL)
 #include "chrome/browser/browser_process.h"
