--- src/tss2-tcti/tctildr-nodl.c.orig	2025-02-22 22:43:21 UTC
+++ src/tss2-tcti/tctildr-nodl.c
@@ -67,7 +67,7 @@ struct {
         .init = Tss2_Tcti_Tbs_Init,
         .description = "Access to TBS",
     },
-#elif defined (__VXWORKS__)
+#elif defined (__VXWORKS__) || defined(__FreeBSD__)
     {
         .names = {
             "libtss2-tcti-device.so.0",
