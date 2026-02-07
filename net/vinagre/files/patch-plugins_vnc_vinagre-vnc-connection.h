--- plugins/vnc/vinagre-vnc-connection.h.orig	2020-08-30 07:00:18 UTC
+++ plugins/vnc/vinagre-vnc-connection.h
@@ -26,7 +26,7 @@
 
 G_BEGIN_DECLS
 
-gboolean scaling_command_line;
+extern gboolean scaling_command_line;
 
 #define VINAGRE_TYPE_VNC_CONNECTION             (vinagre_vnc_connection_get_type ())
 #define VINAGRE_VNC_CONNECTION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), VINAGRE_TYPE_VNC_CONNECTION, VinagreVncConnection))
