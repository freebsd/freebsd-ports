--- chrome/browser/sync/chrome_sync_client.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -411,7 +411,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
       controllers.push_back(
