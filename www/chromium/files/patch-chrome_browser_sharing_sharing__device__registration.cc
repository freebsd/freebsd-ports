--- chrome/browser/sharing/sharing_device_registration.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -325,7 +325,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 }
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kRemoteCopyReceiver);
 #else
