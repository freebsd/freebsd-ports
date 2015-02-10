--- installer/core_install.py.orig	2014-10-07 08:55:35 UTC
+++ installer/core_install.py
@@ -769,14 +769,14 @@ class CoreInstall(object):
             if not check_lib('libusb'):
                 return False
             if self.distro_name != "rhel":
-                return len(locate_file_contains("usb.h", '/usr/include', 'usb_init'))
+                return len(locate_file_contains("usb.h", '%USB_INCLUDE%', 'usb_init'))
             else:
                 return True
         else:
             if not check_lib('libusb-1.0'):
                 return False
             if self.distro_name != "rhel":
-                return len(locate_file_contains("libusb.h", '/usr/include/libusb-1.0', 'libusb_init'))
+                return len(locate_file_contains("libusb.h", '%USB_INCLUDE%', 'libusb_init'))
             else:
                 return True
 
