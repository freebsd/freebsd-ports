--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -56,7 +56,11 @@
 #include "content/public/browser/web_contents.h"
 #include "google_apis/gaia/gaia_urls.h"
 #include "net/base/url_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if defined(OS_MACOSX) || BUILDFLAG(ANDROID_JAVA_UI)
 #include "chrome/browser/password_manager/save_password_infobar_delegate.h"
