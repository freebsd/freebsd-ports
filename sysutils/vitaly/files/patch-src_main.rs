# Fix device discovery on FreeBSD by bypassing zeroed HID usage checks

# The vitaly CLI tool relies on cross-platform hidapi for device enumeration.
# On FreeBSD, the comms/hidapi port is built using the libusb backend. Due to
# architectural limitations of libusb on FreeBSD, it hardcodes both the 
# 'usage_page' and 'usage' properties to 0 during the initial device scanning phase, 
# as parsing full report descriptors would require invasively detaching active 
# kernel drivers.

# Upstream vitaly implements a strict gatekeeping filter requiring an initial match on 
# the QMK/Vial vendor-defined page (usage_page == 0xFF60). Because libusb reports 0, 
# all compatible keyboards fail this static validation check on FreeBSD, resulting in a 
# silent "No matching devices found" error even when run as root.

# Also fixes handling of empty strings of device.manufacturer and/or device.serial_number,
potentially causing println!() invocation to fail/crash silently without any warnings, but
keeping found devices list empty (found = false), ending up with confusing message:
"No matching devices found".
--- src/main.rs.orig	2026-01-14 10:24:28 UTC
+++ src/main.rs
@@ -278,19 +278,17 @@ fn command_for_devices(id: Option<u16>, command: &Comm
         Ok(api) => {
             let mut found = false;
             for device in api.device_list() {
-                if device.usage_page() == protocol::USAGE_PAGE
-                    && device.usage() == protocol::USAGE_ID
-                    && (id.is_none() || id.unwrap() == device.product_id())
+                if true && (id.is_none() || id.unwrap() == device.product_id())
                 {
                     found = true;
                     println!(
                         "Product name: {:?} id: {:?},\nManufacturer name: {:?}, id: {:?},\nRelease: {:?}, Serial: {:?}, Path: {:?}",
                         device.product_string().unwrap(),
                         device.product_id(),
-                        device.manufacturer_string().unwrap(),
+                        device.manufacturer_string().unwrap_or(""),
                         device.vendor_id(),
                         device.release_number(),
-                        device.serial_number().unwrap(),
+                        device.serial_number().unwrap_or(""),
                         device.path(),
                     );
                     let result = match command {
