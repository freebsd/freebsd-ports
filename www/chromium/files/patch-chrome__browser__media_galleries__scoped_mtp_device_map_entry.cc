--- chrome/browser/media_galleries/scoped_mtp_device_map_entry.cc.orig	2013-08-17 22:11:30.000000000 +0300
+++ chrome/browser/media_galleries/scoped_mtp_device_map_entry.cc	2013-08-17 22:12:55.000000000 +0300
@@ -56,6 +56,7 @@
 }
 
 void ScopedMTPDeviceMapEntry::Init() {
+#if !defined(OS_BSD)
   CreateMTPDeviceAsyncDelegateCallback callback =
       base::Bind(&ScopedMTPDeviceMapEntry::OnMTPDeviceAsyncDelegateCreated,
                  this);
@@ -65,6 +66,7 @@
       base::Bind(&CreateMTPDeviceAsyncDelegate,
                  device_location_,
                  callback));
+#endif
 }
 
 ScopedMTPDeviceMapEntry::~ScopedMTPDeviceMapEntry() {
