--- src/chrome/browser/updater/updater.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/updater/updater.cc
@@ -53,7 +53,7 @@ std::optional<mojom::AppState> GetLastKn
   return GetLastKnownUpdaterRegistrationStorage();
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void CheckForUpdate(
     base::RepeatingCallback<void(const UpdateService::UpdateState&)> callback) {
   base::ThreadPool::PostTaskAndReplyWithResult(
