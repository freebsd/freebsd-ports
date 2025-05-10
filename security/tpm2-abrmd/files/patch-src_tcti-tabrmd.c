--- src/tcti-tabrmd.c.orig	2025-02-22 21:59:15 UTC
+++ src/tcti-tabrmd.c
@@ -46,7 +46,7 @@ tss2_tcti_tabrmd_transmit (TSS2_TCTI_CONTEXT *context,
     g_debug_bytes (command, size, 16, 4);
     ostream = g_io_stream_get_output_stream (TSS2_TCTI_TABRMD_IOSTREAM (context));
     g_debug ("%s: blocking write on ostream", __func__);
-    write_ret = write_all (ostream, command, size);
+    write_ret = g_write_all (ostream, command, size);
     /* should switch on possible errors to translate to TSS2 error codes */
     switch (write_ret) {
     case -1:
