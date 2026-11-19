--- services/device/usb/usb_device_handle_usbfs.cc.orig	2026-11-19 12:25:27 UTC
+++ services/device/usb/usb_device_handle_usbfs.cc
@@ -35,7 +35,7 @@
 #include "chromeos/dbus/permission_broker/permission_broker_client.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_macros.h"
 #include "services/device/usb/usb_interface_detach_allowlist.h"
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
@@ -51,7 +51,7 @@ using mojom::UsbTransferType;
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Outcome of detaching a kernel driver before ClaimInterface().
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
@@ -318,7 +318,7 @@ bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::R
   return true;
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::DetachInterface(
     int interface_number,
     const CombinedInterfaceInfo& interface_info) {
@@ -672,7 +672,7 @@ void UsbDeviceHandleUsbfs::ClaimInterface(int interfac
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     const mojom::UsbConfigurationInfo* config =
         device_->GetActiveConfiguration();
@@ -1063,7 +1063,7 @@ void UsbDeviceHandleUsbfs::ReleaseInterfaceComplete(in
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     helper_.AsyncCall(&BlockingTaskRunnerHelper::ReattachInterface)
         .WithArgs(interface_number)
