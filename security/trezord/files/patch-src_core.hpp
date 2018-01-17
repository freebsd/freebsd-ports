--- src/core.hpp.orig	2017-12-02 14:37:41 UTC
+++ src/core.hpp
@@ -195,12 +195,12 @@ public:
           pb_wire_codec{new protobuf::wire_codec{pb_state.get()}},
           pb_json_codec{new protobuf::json_codec{pb_state.get()}}
     {
-        hid::init();
+        usb::init();
     }
 
     ~kernel()
     {
-        hid::exit();
+        usb::exit();
     }
 
     std::string
@@ -433,13 +433,13 @@ private:
     enumerate_supported_devices()
     {
         return wire::enumerate_connected_devices(
-            [&] (hid_device_info const *i) {
+            [&] (usb::usb_device_info const *i) {
                 return is_device_supported(i);
             });
     }
 
     bool
-    is_device_supported(hid_device_info const *info)
+    is_device_supported(usb::usb_device_info const *info)
     {
         return std::any_of(
             config.c.known_devices().begin(),
