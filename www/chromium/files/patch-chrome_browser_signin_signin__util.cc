--- chrome/browser/signin/signin_util.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -42,7 +42,7 @@ namespace {
 
 constexpr char kSignoutSettingKey[] = "signout_setting";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #define CAN_DELETE_PROFILE
 #endif
 
