--- chrome/browser/signin/signin_util.cc.orig	2019-09-09 21:55:10 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -34,7 +34,7 @@
 #include "google_apis/gaia/gaia_auth_util.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
@@ -46,7 +46,7 @@ namespace {
 
 constexpr char kSignoutSettingKey[] = "signout_setting";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #define CAN_DELETE_PROFILE
 #endif
 
