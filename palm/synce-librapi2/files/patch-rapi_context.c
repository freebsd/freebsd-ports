--- src/support/rapi_context.c	2009-07-27 13:25:07.000000000 +0400
+++ src/support/rapi_context.c	2009-07-27 13:26:52.000000000 +0400
@@ -513,13 +513,19 @@
         /*
          *  odccm, synce-hal, or proxy ?
          */
+#if ENABLE_ODCCM_SUPPORT
         if (strcmp(transport, "odccm") == 0) {
             synce_socket_take_descriptor(context->socket, get_connection_from_odccm(info));
         }
-        else if (strcmp(transport, "hal") == 0) {
+        else
+#endif
+#if ENABLE_HAL_SUPPORT
+        if (strcmp(transport, "hal") == 0) {
             synce_socket_take_descriptor(context->socket, get_connection_from_hal(info));
         }
-        else if ( !synce_socket_connect_proxy(context->socket, synce_info_get_device_ip(info)) )
+        else
+#endif
+	if ( !synce_socket_connect_proxy(context->socket, synce_info_get_device_ip(info)) )
         {
             synce_error("failed to connect to proxy for %s", synce_info_get_device_ip(info));
             goto fail;
