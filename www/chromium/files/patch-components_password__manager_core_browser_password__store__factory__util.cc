--- components/password_manager/core/browser/password_store_factory_util.cc.orig	2024-09-30 07:45:04 UTC
+++ components/password_manager/core/browser/password_store_factory_util.cc
@@ -28,7 +28,7 @@ namespace {
 LoginDatabase::DeletingUndecryptablePasswordsEnabled GetPolicyFromPrefs(
     PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return LoginDatabase::DeletingUndecryptablePasswordsEnabled(
       prefs->GetBoolean(prefs::kDeletingUndecryptablePasswordsEnabled));
 #else
