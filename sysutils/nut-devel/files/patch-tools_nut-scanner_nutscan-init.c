--- tools/nut-scanner/nutscan-init.c.orig	2022-08-15 05:15:58.000000000 -0700
+++ tools/nut-scanner/nutscan-init.c	2022-08-15 07:11:39.489088000 -0700
@@ -135,7 +135,11 @@
 	char *libname = NULL;
 #ifdef WITH_USB
  #if WITH_LIBUSB_1_0
+  #ifdef __FreeBSD__
+	libname = get_libname("libusb.so");
+  #else
 	libname = get_libname("libusb-1.0" SOEXT);
+  #endif
  #else
 	libname = get_libname("libusb-0.1" SOEXT);
  #endif
