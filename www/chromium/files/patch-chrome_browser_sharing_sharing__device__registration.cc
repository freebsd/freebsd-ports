--- chrome/browser/sharing/sharing_device_registration.cc.orig	2020-03-26 18:39:48 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -325,7 +325,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 }
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kRemoteCopyReceiver);
 #endif
@@ -334,10 +334,10 @@ bool SharingDeviceRegistration::IsRemoteCopySupported(
 }
 
 bool SharingDeviceRegistration::IsPeerConnectionSupported() const {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kSharingPeerConnectionReceiver);
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
   return false;
