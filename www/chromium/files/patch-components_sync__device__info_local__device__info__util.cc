--- components/sync_device_info/local_device_info_util.cc.orig	2022-09-24 10:57:32 UTC
+++ components/sync_device_info/local_device_info_util.cc
@@ -78,7 +78,7 @@ void OnMachineStatisticsLoaded(LocalDeviceNameInfo* na
 sync_pb::SyncEnums::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return sync_pb::SyncEnums_DeviceType_TYPE_CROS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return sync_pb::SyncEnums_DeviceType_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   return ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET
