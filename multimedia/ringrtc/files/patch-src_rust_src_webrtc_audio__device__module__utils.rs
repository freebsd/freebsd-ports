--- src/rust/src/webrtc/audio_device_module_utils.rs.orig	2024-11-18 16:04:01.050553000 +0100
+++ src/rust/src/webrtc/audio_device_module_utils.rs	2024-11-18 16:06:58.737883000 +0100
@@ -17,7 +17,7 @@ pub struct DeviceCollectionWrapper<'a> {
     device_collection: DeviceCollection<'a>,
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn device_is_monitor(device: &DeviceInfo) -> bool {
     device.device_type() == cubeb::DeviceType::INPUT
         && device
@@ -41,7 +41,7 @@ impl DeviceCollectionWrapper<'_> {
     }
 
     // For linux only, a method that will ignore "monitor" devices.
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "freebsd", target_os = "linux"))]
     pub fn iter_non_monitor(
         &self,
     ) -> std::iter::Filter<std::slice::Iter<'_, DeviceInfo>, fn(&&DeviceInfo) -> bool> {
@@ -82,7 +82,7 @@ impl DeviceCollectionWrapper<'_> {
             {
                 self.iter().nth(idx - 1)
             }
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "freebsd", target_os = "linux"))]
             {
                 // filter out "monitor" devices.
                 self.iter_non_monitor().nth(idx - 1)
@@ -112,7 +112,7 @@ impl DeviceCollectionWrapper<'_> {
         let count = self.iter().count();
         // Whether a monitor device is default or not, there will be an additional default,
         // so no need to do anything different.
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "freebsd", target_os = "linux"))]
         let count = self.iter_non_monitor().count();
         if count == 0 {
             0
