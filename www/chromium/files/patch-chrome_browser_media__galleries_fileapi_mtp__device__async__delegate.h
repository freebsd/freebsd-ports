--- chrome/browser/media_galleries/fileapi/mtp_device_async_delegate.h.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/media_galleries/fileapi/mtp_device_async_delegate.h
@@ -209,7 +209,7 @@ class MTPDeviceAsyncDelegate {
   virtual ~MTPDeviceAsyncDelegate() = default;
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 typedef base::OnceCallback<void(MTPDeviceAsyncDelegate*)>
     CreateMTPDeviceAsyncDelegateCallback;
 
