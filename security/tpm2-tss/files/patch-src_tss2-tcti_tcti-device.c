--- src/tss2-tcti/tcti-device.c.orig	2023-01-23 18:36:16.000000000 +0000
+++ src/tss2-tcti/tcti-device.c	2025-05-08 08:40:29.255475000 +0000
@@ -61,7 +61,9 @@
 #ifdef __VXWORKS__
     "/tpm0"
 #else
+#ifndef __FreeBSD__
     "/dev/tpmrm0",
+#endif /* __FreeBSD__ */
     "/dev/tpm0",
 #endif /* __VX_WORKS__ */
 };
