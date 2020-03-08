--- components/sync_device_info/device_info_sync_bridge.cc.orig	2020-03-03 18:53:54 UTC
+++ components/sync_device_info/device_info_sync_bridge.cc
@@ -445,11 +445,13 @@ void DeviceInfoSyncBridge::OnStoreCreated(
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
