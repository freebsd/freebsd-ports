--- cmake/FindLibusb.cmake.orig	2022-10-19 18:04:24 UTC
+++ cmake/FindLibusb.cmake
@@ -12,14 +12,14 @@ mark_as_advanced(Libusb_VERSION)
 # Find header path
 find_path(
   Libusb_INCLUDE_DIR
-  NAMES libusb-1.0/libusb.h
+  NAMES libusb.h
   HINTS ${PC_Libusb_INCLUDE_DIRS})
 mark_as_advanced(Libusb_INCLUDE_DIR)
 
 # Find lib path
 find_library(
   Libusb_LIBRARIES
-  NAMES usb-1.0
+  NAMES usb
   HINTS ${PC_Libusb_LIBRARY_DIRS})
 mark_as_advanced(Libusb_LIBRARIES)
 
