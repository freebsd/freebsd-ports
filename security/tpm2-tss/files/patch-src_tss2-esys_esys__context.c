--- src/tss2-esys/esys_context.c.orig	2025-02-22 22:43:21 UTC
+++ src/tss2-esys/esys_context.c
@@ -26,7 +26,7 @@
  * If not specified, load a TCTI in this order:
  *       Library libtss2-tcti-default.so (link to the preferred TCTI)
  *       Library libtss2-tcti-tabrmd.so (tabrmd)
- *       Device /dev/tpmrm0 (kernel resident resource manager)
+ *       Device /dev/tpmrm0 (kernel resident resource manager, SKIPPED on FreeBSD)
  *       Device /dev/tpm0 (hardware TPM)
  *       TCP socket localhost:2321 (TPM simulator)
  * @param esys_context [out] The ESYS_CONTEXT.
