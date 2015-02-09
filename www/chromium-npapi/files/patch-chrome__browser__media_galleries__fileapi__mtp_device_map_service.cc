--- ./chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2014-04-30 22:42:13.000000000 +0200
+++ ./chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc	2014-05-04 14:38:46.000000000 +0200
@@ -33,9 +33,11 @@
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !defined(OS_FREEBSD)
     CreateMTPDeviceAsyncDelegate(device_location,
         base::Bind(&MTPDeviceMapService::AddAsyncDelegate,
                    base::Unretained(this), device_location));
+#endif
     mtp_device_usage_map_[device_location] = 0;
   }
 
