--- src/rapi2/file_management2.c.orig	Fri Jan 26 02:12:41 2007
+++ src/rapi2/file_management2.c	Fri Jan 26 02:13:40 2007
@@ -40,6 +40,7 @@
 {
     RapiContext* context = rapi_context_current();
     uint32_t count = 0;
+    uint32_t unknown;
 
     rapi_context_begin_command(context, 0x1a);
     rapi2_buffer_write_string(context->send_buffer, szPath);
@@ -50,7 +51,7 @@
 
     /* TODO Don't know this two uint32_t fields */
     rapi_buffer_read_uint32(context->recv_buffer, &context->last_error);
-    uint32_t unknown;
+
     rapi_buffer_read_uint32(context->recv_buffer, &unknown);
 
     rapi_buffer_read_uint32(context->recv_buffer, &count);
