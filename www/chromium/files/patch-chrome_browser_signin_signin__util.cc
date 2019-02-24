--- chrome/browser/signin/signin_util.cc.orig	2019-02-06 22:35:27.697597000 +0100
+++ chrome/browser/signin/signin_util.cc	2019-02-06 22:35:53.931412000 +0100
@@ -40,7 +40,7 @@
 
 constexpr char kSignoutSettingKey[] = "signout_setting";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #define CAN_DELETE_PROFILE
 #endif
 
