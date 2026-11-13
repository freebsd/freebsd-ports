--- src/rust/src/webrtc/audio_device_module_utils.rs.orig	2024-11-18 16:04:01 UTC
+++ src/rust/src/webrtc/audio_device_module_utils.rs
@@ -51,7 +51,7 @@ fn device_is_pulse_monitor(device: &MinimalDeviceInfo)
 /// monitor devices. (However, this is not absolute -- if a user's **system preferred** input
 /// device is a monitor, we respect that)
 fn device_is_pulse_monitor(device: &MinimalDeviceInfo) -> bool {
-    cfg!(target_os = "linux")
+    cfg!(target_os = "linux") || cfg!(target_os = "freebsd")
         && device.device_type == cubeb::DeviceType::INPUT
         && device.device_id.ends_with(".monitor")
 }
@@ -305,7 +305,7 @@ fn cubeb_redaction_specs() -> &'static Vec<RedactionSp
                 ],
             });
         }
-        if cfg!(target_os = "linux") || cfg!(test) {
+        if cfg!(target_os = "linux") || cfg!(target_os = "freebsd") || cfg!(test) {
             // cubeb-pulse-rs context.rs server_info_cb::sink_info_cb
             out.push(RedactionSpec {
                 first_to_keep: regex_aot::regex!("PulseAudio default sink info: name="),
