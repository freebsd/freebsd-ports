--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -62,7 +62,11 @@
 #include "net/base/url_util.h"
 #include "net/http/transport_security_state.h"
 #include "net/url_request/url_request_context.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if defined(OS_ANDROID)
 #include "chrome/browser/android/tab_android.h"
