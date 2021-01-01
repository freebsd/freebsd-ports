--- chrome/browser/search/search_suggest/search_suggest_service.cc.orig	2019-12-16 21:50:43 UTC
+++ chrome/browser/search/search_suggest/search_suggest_service.cc
@@ -20,7 +20,11 @@
 #include "components/prefs/scoped_user_pref_update.h"
 #include "components/signin/public/identity_manager/accounts_in_cookie_jar_info.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace {
 
