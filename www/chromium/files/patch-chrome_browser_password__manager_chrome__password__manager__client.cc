--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-03-09 20:04:28 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -57,7 +57,11 @@
 #include "content/public/common/origin_util.h"
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if defined(OS_ANDROID)
 #include "chrome/browser/android/tab_android.h"
