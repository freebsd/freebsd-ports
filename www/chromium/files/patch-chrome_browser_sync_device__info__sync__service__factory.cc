--- chrome/browser/sync/device_info_sync_service_factory.cc.orig	2021-01-19 11:26:56 UTC
+++ chrome/browser/sync/device_info_sync_service_factory.cc
@@ -42,12 +42,12 @@ class DeviceInfoSyncClient : public syncer::DeviceInfo
   std::string GetSigninScopedDeviceId() const override {
 // Since the local sync backend is currently only supported on Windows, Mac and
 // Linux don't even check the pref on other os-es.
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     syncer::SyncPrefs prefs(profile_->GetPrefs());
     if (prefs.IsLocalSyncEnabled()) {
       return "local_device";
     }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
     return GetSigninScopedDeviceIdForProfile(profile_);
   }
