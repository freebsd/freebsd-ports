--- src/system_control.c.orig	Sat Dec 31 14:38:07 2005
+++ src/system_control.c	Sat Dec 31 14:38:20 2005
@@ -1756,7 +1756,7 @@ bmp_system_control_init (BmpSystemContro
 
     if (!dbus_g_proxy_call (bus_proxy, "RequestName", &error,
 			    G_TYPE_STRING, BMP_DBUS_INTERFACE,
-			    G_TYPE_UINT, DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT,
+			    G_TYPE_UINT, DBUS_NAME_FLAG_DO_NOT_QUEUE,
 			    G_TYPE_INVALID,
 			    G_TYPE_UINT, &request_name_result,
 			    G_TYPE_INVALID))
