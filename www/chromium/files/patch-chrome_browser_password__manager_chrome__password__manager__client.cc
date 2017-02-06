--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -57,7 +57,11 @@
 #include "content/public/browser/web_contents.h"
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if BUILDFLAG(ANDROID_JAVA_UI)
 #include "chrome/browser/android/tab_android.h"
