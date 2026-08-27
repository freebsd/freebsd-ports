--- os_freebsd.cpp.orig	2023-03-14 13:01:29.000000000 -0700
+++ os_freebsd.cpp	2026-08-26 21:29:57.941276000 -0700
@@ -2224,7 +2224,11 @@
   uint8_t n;
   struct LIBUSB20_DEVICE_DESC_DECODED *pdesc;
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1600020
+  pbe = libusb20_be_alloc_default(NULL);
+#else
   pbe = libusb20_be_alloc_default();
+#endif
 
   while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
     matches++;
