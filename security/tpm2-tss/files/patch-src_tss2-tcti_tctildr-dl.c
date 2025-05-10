--- src/tss2-tcti/tctildr-dl.c.orig	2025-02-22 22:43:21 UTC
+++ src/tss2-tcti/tctildr-dl.c
@@ -37,11 +37,13 @@ struct {
         .file = "libtss2-tcti-tabrmd.so.0",
         .description = "Access libtss2-tcti-tabrmd.so",
     },
+#if !defined(__FreeBSD__)
     {
         .file = "libtss2-tcti-device.so.0",
         .conf = "/dev/tpmrm0",
         .description = "Access libtss2-tcti-device.so.0 with /dev/tpmrm0",
     },
+#endif
     {
         .file = "libtss2-tcti-device.so.0",
         .conf = "/dev/tpm0",
