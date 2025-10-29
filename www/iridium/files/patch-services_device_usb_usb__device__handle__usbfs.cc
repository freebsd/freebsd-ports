--- services/device/usb/usb_device_handle_usbfs.cc.orig	2025-10-28 14:29:43 UTC
+++ services/device/usb/usb_device_handle_usbfs.cc
@@ -34,7 +34,7 @@
 #include "chromeos/dbus/permission_broker/permission_broker_client.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_macros.h"
 #include "services/device/public/cpp/device_features.h"
 #include "services/device/usb/usb_interface_detach_allowlist.h"
@@ -51,7 +51,7 @@ using mojom::UsbTransferType;
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Outcome of detaching a kernel driver before ClaimInterface().
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
@@ -293,7 +293,7 @@ bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::R
   return true;
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::DetachInterface(
     int interface_number,
     const CombinedInterfaceInfo& interface_info) {
@@ -630,7 +630,7 @@ void UsbDeviceHandleUsbfs::ClaimInterface(int interfac
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     const mojom::UsbConfigurationInfo* config =
         device_->GetActiveConfiguration();
@@ -976,7 +976,7 @@ void UsbDeviceHandleUsbfs::ReleaseInterfaceComplete(in
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     helper_.AsyncCall(&BlockingTaskRunnerHelper::ReattachInterface)
         .WithArgs(interface_number)
