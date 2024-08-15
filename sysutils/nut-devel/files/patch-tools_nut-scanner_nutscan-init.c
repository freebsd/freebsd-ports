--- tools/nut-scanner/nutscan-init.c.orig	2024-07-17 06:41:06.000000000 -0700
+++ tools/nut-scanner/nutscan-init.c	2024-07-18 13:41:55.306142000 -0700
@@ -216,7 +216,11 @@
 	}
 #  endif	/* SOFILE_LIBUSB1 */
 	if (!libname) {
+#    ifdef __FreeBSD__
+		libname = get_libname("libusb.so");
+#    else
 		libname = get_libname("libusb-1.0" SOEXT);
+#    endif
 	}
 #  ifdef SOPATH_LIBUSB1
 	if (!libname) {
