--- chrome/browser/sync/device_info_sync_client_impl.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/sync/device_info_sync_client_impl.cc
@@ -41,7 +41,7 @@ std::string DeviceInfoSyncClientImpl::GetSigninScopedD
 // included in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   syncer::SyncPrefs prefs(profile_->GetPrefs());
   if (prefs.IsLocalSyncEnabled()) {
     return "local_device";
