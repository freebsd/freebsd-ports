diff --git tools/nut-scanner/nutscan-init.c.orig tools/nut-scanner/nutscan-init.c
index 9ea3f5d..13f4e78 100644
--- tools/nut-scanner/nutscan-init.c.orig
+++ tools/nut-scanner/nutscan-init.c
@@ -133,7 +133,11 @@ void nutscan_init(void)
 	char *libname = NULL;
 #ifdef WITH_USB
  #if WITH_LIBUSB_1_0
+  #ifdef __FreeBSD__
+	libname = get_libname("libusb.so");
+  #else
 	libname = get_libname("libusb-1.0.so");
+  #endif
  #else
 	libname = get_libname("libusb-0.1.so");
 	if (!libname) {
