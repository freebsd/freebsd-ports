--- headless/lib/browser/headless_request_context_manager.cc.orig	2022-02-28 16:54:41 UTC
+++ headless/lib/browser/headless_request_context_manager.cc
@@ -65,7 +65,7 @@ void SetCryptKeyOnce(const base::FilePath& user_data_p
     return;
   done_once = true;
 
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
   // The OSCrypt keys are process bound, so if network service is out of
   // process, send it the required key if it is available.
   if (content::IsOutOfProcessNetworkService()
