--- src/wire.hpp.orig	2017-12-02 14:37:41 UTC
+++ src/wire.hpp
@@ -57,13 +57,14 @@ device_info_list
 enumerate_connected_devices(F filter)
 {
     device_info_list list;
-    auto *infos = hid::enumerate(0x00, 0x00);
+    auto *infos = usb::enumerate(0x00, 0x00);
 
     for (auto i = infos; i != nullptr; i = i->next) {
         // skip unsupported devices
         if (!filter(i)) {
             continue;
         }
+#if 0
         // skip foreign interfaces
         if (i->interface_number > 0) {
             CLOG(DEBUG, "wire.enumerate") << "skipping, invalid device";
@@ -79,6 +80,7 @@ enumerate_connected_devices(F filter)
             CLOG(DEBUG, "wire.enumerate") << "skipping, fido interface";
             continue;
         }
+#endif
         list.emplace_back(
             device_info{
                 i->vendor_id,
@@ -86,7 +88,7 @@ enumerate_connected_devices(F filter)
                 i->path});
     }
 
-    hid::free_enumeration(infos);
+    usb::free_enumeration(infos);
     return list;
 }
 
@@ -112,18 +114,19 @@ struct device
 
     device(char const *path)
     {
-        hid = hid::open_path(path);
+        hid = usb::open_path(path);
         if (!hid) {
             throw open_error("HID device open failed");
         }
-        hid_version = try_hid_version();
+        hid_version = 1; // no report with libusb try_hid_version();
         if (hid_version <= 0) {
             throw open_error("Unknown HID version");
         }
     }
 
-    ~device() { hid::close(hid); }
+    ~device() { usb::close(hid); }
 
+#if 0
     // try writing packet that will be discarded to figure out hid version
     int try_hid_version() {
         int r;
@@ -133,7 +136,7 @@ struct device
         report.fill(0xFF);
         report[0] = 0x00;
         report[1] = 0x3F;
-        r = hid::write(hid, report.data(), 65);
+        r = usb::write(hid, report.data(), 65);
         if (r == 65) {
             return 2;
         }
@@ -141,7 +144,7 @@ struct device
         // try version 1
         report.fill(0xFF);
         report[0] = 0x3F;
-        r = hid::write(hid, report.data(), 64);
+        r = usb::write(hid, report.data(), 64);
         if (r == 64) {
             return 1;
         }
@@ -149,6 +152,7 @@ struct device
         // unknown version
         return 0;
     }
+#endif
 
     void
     read_buffered(char_type *data,
@@ -210,7 +214,7 @@ private:
         int r;
 
         do {
-            r = hid::read_timeout(hid, report.data(), report.size(), 50);
+            r = usb::read(hid, report.data(), report.size());
         } while (r == 0);
 
         if (r < 0) {
@@ -251,7 +255,7 @@ private:
                 break;
         }
 
-        int r = hid::write(hid, report.data(), report_size);
+        int r = usb::write(hid, report.data(), report_size);
         if (r < 0) {
             throw write_error{"HID device write failed"};
         }
@@ -263,9 +267,9 @@ private:
     }
 
     typedef std::vector<char_type> buffer_type;
-    typedef std::array<char_type, 65> report_type;
+    typedef std::array<char_type, 64> report_type;
 
-    hid_device *hid;
+    libusb_device_handle *hid;
     buffer_type read_buffer;
     int hid_version;
 };
