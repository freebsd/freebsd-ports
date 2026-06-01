--- src/tss2-tcti/tcti-device.c.orig	2024-05-21 12:44:23 UTC
+++ src/tss2-tcti/tcti-device.c
@@ -61,7 +61,9 @@ static char *default_conf[] = {
 #ifdef __VXWORKS__
     "/tpm0"
 #else
+#ifndef __FreeBSD__
     "/dev/tpmrm0",
+#endif /* __FreeBSD__ */
     "/dev/tpm0",
     "/dev/tcm0",
 #endif /* __VX_WORKS__ */
