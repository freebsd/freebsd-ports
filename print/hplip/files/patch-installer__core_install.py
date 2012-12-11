--- ./installer/core_install.py.orig	2012-09-04 12:31:53.000000000 +0000
+++ ./installer/core_install.py	2012-09-12 15:01:59.259583493 +0000
@@ -885,7 +885,7 @@
             if not check_lib('libusb'):
                 return False
             if self.distro_name != "rhel":
-                return len(locate_file_contains("usb.h", '/usr/include', 'usb_init'))
+                return len(locate_file_contains("usb.h", '%USB_INCLUDE%', 'usb_init'))
             else:
                 return True
         else:
