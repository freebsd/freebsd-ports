--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -80,7 +80,11 @@
 #include "net/cert/cert_status_flags.h"
 #include "services/identity/public/cpp/identity_manager.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/url_constants.h"
 
 #if defined(SAFE_BROWSING_DB_LOCAL)
