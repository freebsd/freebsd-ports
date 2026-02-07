--- components/password_manager/core/browser/password_store_factory_util.cc.orig	2025-10-30 15:44:36 UTC
+++ components/password_manager/core/browser/password_store_factory_util.cc
@@ -33,7 +33,7 @@ namespace {
 LoginDatabase::DeletingUndecryptablePasswordsEnabled GetPolicyFromPrefs(
     PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return LoginDatabase::DeletingUndecryptablePasswordsEnabled(
       prefs->GetBoolean(prefs::kDeletingUndecryptablePasswordsEnabled));
 #else
