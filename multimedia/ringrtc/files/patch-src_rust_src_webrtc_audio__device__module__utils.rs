--- src/rust/src/webrtc/audio_device_module_utils.rs.orig	2024-11-18 16:04:01 UTC
+++ src/rust/src/webrtc/audio_device_module_utils.rs
@@ -11,7 +11,7 @@ use cubeb_core::DevicePref;
 use anyhow::anyhow;
 use cubeb::{DeviceCollection, DeviceState};
 use cubeb_core::DevicePref;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 use cubeb_core::DeviceType;
 use regex::Regex;
 
@@ -22,7 +22,7 @@ pub struct MinimalDeviceInfo {
     pub devid: *const c_void,
     pub device_id: Option<String>,
     pub friendly_name: Option<String>,
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "freebsd", target_os = "linux"))]
     device_type: DeviceType,
     preferred: DevicePref,
     state: DeviceState,
@@ -40,7 +40,7 @@ pub struct DeviceCollectionWrapper {
     device_collection: Vec<MinimalDeviceInfo>,
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn device_is_monitor(device: &MinimalDeviceInfo) -> bool {
     device.device_type == DeviceType::INPUT
         && device
@@ -57,7 +57,7 @@ impl DeviceCollectionWrapper {
                 devid: device.devid(),
                 device_id: device.device_id().as_ref().map(|s| s.to_string()),
                 friendly_name: device.friendly_name().as_ref().map(|s| s.to_string()),
-                #[cfg(target_os = "linux")]
+                #[cfg(any(target_os = "freebsd", target_os = "linux"))]
                 device_type: device.device_type(),
                 preferred: device.preferred(),
                 state: device.state(),
@@ -79,7 +79,7 @@ impl DeviceCollectionWrapper {
     }
 
     // For linux only, a method that will ignore "monitor" devices.
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "freebsd", target_os = "linux"))]
     pub fn iter_non_monitor(
         &self,
     ) -> std::iter::Filter<std::slice::Iter<'_, MinimalDeviceInfo>, fn(&&MinimalDeviceInfo) -> bool>
@@ -121,7 +121,7 @@ impl DeviceCollectionWrapper {
             {
                 self.iter().nth(idx - 1)
             }
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "freebsd", target_os = "linux"))]
             {
                 // filter out "monitor" devices.
                 self.iter_non_monitor().nth(idx - 1)
@@ -149,12 +149,12 @@ impl DeviceCollectionWrapper {
     pub fn count(&self) -> usize {
         #[cfg(target_os = "macos")]
         let count = self.iter().count();
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "freebsd", target_os = "linux"))]
         let count = self.iter_non_monitor().count();
         if count == 0 {
             #[cfg(target_os = "macos")]
             return 0;
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "freebsd", target_os = "linux"))]
             return
                 // edge case: if there are only monitor devices, and one is the default,
                 // allow it.
