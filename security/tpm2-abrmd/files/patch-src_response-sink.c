--- src/response-sink.c.orig	2025-02-22 21:59:15 UTC
+++ src/response-sink.c
@@ -188,7 +188,7 @@ response_sink_process_response (Tpm2Response *response
 
     g_debug ("%s: writing 0x%x bytes", __func__, size);
     g_debug_bytes (buffer, size, 16, 4);
-    written = write_all (ostream, buffer, size);
+    written = g_write_all (ostream, buffer, size);
     g_object_unref (connection);
 
     return written;
