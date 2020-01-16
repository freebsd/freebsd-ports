--- components/sync_device_info/device_info_sync_bridge.cc.orig	2019-12-31 14:39:30 UTC
+++ components/sync_device_info/device_info_sync_bridge.cc
@@ -432,11 +432,13 @@ void DeviceInfoSyncBridge::OnStoreCreated(
     return;
   }
 
+#if !defined(OS_BSD)
   store_ = std::move(store);
 
   base::SysInfo::GetHardwareInfo(
       base::BindOnce(&DeviceInfoSyncBridge::OnHardwareInfoRetrieved,
                      weak_ptr_factory_.GetWeakPtr()));
+#endif
 }
 
 void DeviceInfoSyncBridge::OnHardwareInfoRetrieved(
