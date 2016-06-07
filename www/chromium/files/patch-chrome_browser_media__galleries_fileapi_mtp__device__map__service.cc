--- chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2016-03-25 13:04:45 UTC
+++ chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc
@@ -37,10 +37,12 @@ void MTPDeviceMapService::RegisterMTPFil
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !defined(OS_FREEBSD)
     CreateMTPDeviceAsyncDelegate(
         device_location, read_only,
         base::Bind(&MTPDeviceMapService::AddAsyncDelegate,
                    base::Unretained(this), device_location, read_only));
+#endif
     mtp_device_usage_map_[key] = 0;
   }
 
