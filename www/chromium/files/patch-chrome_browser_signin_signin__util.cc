--- chrome/browser/signin/signin_util.cc.orig	2019-07-24 18:58:11 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -33,7 +33,7 @@
 #include "services/identity/public/cpp/primary_account_mutator.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
@@ -45,7 +45,7 @@ namespace {
 
 constexpr char kSignoutSettingKey[] = "signout_setting";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #define CAN_DELETE_PROFILE
 #endif
 
