--- scan/sane/io.c.orig	2022-02-23 07:41:05 UTC
+++ scan/sane/io.c
@@ -92,9 +92,10 @@ int __attribute__ ((visibility ("hidden"))) SendScanEv
         DBUS_TYPE_STRING, &title, 
         DBUS_TYPE_INVALID);
 
-    if (!dbus_connection_send(dbus_conn, msg, NULL))
+    if (NULL == dbus_conn || !dbus_connection_send(dbus_conn, msg, NULL))
     {
         BUG("dbus message send failed!\n");
+        dbus_message_unref(msg);
         return 0;
     }
 
