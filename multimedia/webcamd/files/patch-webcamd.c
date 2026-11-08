--- webcamd.c.orig	2022-07-13 09:52:22.000000000 -0700
+++ webcamd.c	2026-08-19 07:26:33.136369000 -0700
@@ -610,7 +610,11 @@
 	struct find_match *first_match = NULL;
 	struct find_match *curr_match = NULL;
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1600020
+	pbe = libusb20_be_alloc_default(NULL);
+#else
 	pbe = libusb20_be_alloc_default();
+#endif
 	if (pbe == NULL)
 		v4b_errx(EX_SOFTWARE, "Cannot allocate USB backend");
 
