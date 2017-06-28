--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -63,7 +63,11 @@
 #include "extensions/features/features.h"
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if defined(SAFE_BROWSING_DB_LOCAL) || defined(SAFE_BROWSING_DB_REMOTE)
 #include "chrome/browser/browser_process.h"
