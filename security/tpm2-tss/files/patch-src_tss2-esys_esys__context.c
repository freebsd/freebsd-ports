--- src/tss2-esys/esys_context.c.orig	2024-05-17 08:04:10 UTC
+++ src/tss2-esys/esys_context.c
@@ -26,7 +26,7 @@
  * If not specified, load a TCTI in this order:
  *       Library libtss2-tcti-default.so (link to the preferred TCTI)
  *       Library libtss2-tcti-tabrmd.so (tabrmd)
- *       Device /dev/tpmrm0 (kernel resident resource manager)
+ *       Device /dev/tpmrm0 (kernel resident resource manager, SKIPPED on FreeBSD)
  *       Device /dev/tpm0 (hardware TPM)
  *       Device /dev/tcm0 (hardware TCM)
  *       TCP socket localhost:2321 (TPM simulator)
