--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2013-11-16 01:16:27.000000000 +0100
+++ chrome/browser/media_galleries/media_file_system_registry.cc	2013-11-17 23:26:00.000000000 +0100
@@ -68,11 +68,13 @@
 void InitMTPDeviceAsyncDelegate(
     const base::FilePath::StringType& device_location) {
   DCHECK(content::BrowserThread::CurrentlyOn(content::BrowserThread::UI));
+#if !defined(OS_FREEBSD)
   content::BrowserThread::PostTask(
       content::BrowserThread::IO, FROM_HERE, base::Bind(
           &CreateMTPDeviceAsyncDelegate,
           device_location,
           base::Bind(&OnMTPDeviceAsyncDelegateCreated, device_location)));
+#endif
 }
 
 }  // namespace
