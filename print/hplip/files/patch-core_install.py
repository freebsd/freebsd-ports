--- ./installer/core_install.py.orig	2010-08-26 02:29:22.000000000 +0400
+++ ./installer/core_install.py	2010-08-26 02:30:22.429959790 +0400
@@ -833,7 +833,7 @@
         if not check_lib('libusb'):
             return False
 
-        return len(locate_file_contains("usb.h", '/usr/include', 'usb_init(void)'))
+        return len(locate_file_contains("usb.h", '%USB_INCLUDE%', 'usb_init(void)'))
 
 
     def check_libjpeg(self):
