--- chrome/browser/sharing/sharing_device_registration.cc.orig	2021-04-14 18:40:55 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -324,7 +324,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 }
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kRemoteCopyReceiver);
 #else
