--- chrome/browser/sharing/sharing_device_registration.cc.orig	2020-05-13 18:39:38 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -328,7 +328,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 }
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kRemoteCopyReceiver);
 #else
@@ -337,7 +337,7 @@ bool SharingDeviceRegistration::IsRemoteCopySupported(
 }
 
 bool SharingDeviceRegistration::IsPeerConnectionSupported() const {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return base::FeatureList::IsEnabled(kSharingPeerConnectionReceiver);
 #else
