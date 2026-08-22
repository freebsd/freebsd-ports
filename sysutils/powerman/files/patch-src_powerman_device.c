--- src/powerman/device.c.orig	2024-09-11 17:18:33 UTC
+++ src/powerman/device.c
@@ -916,7 +916,7 @@ static void _process_action(Device * dev, struct timev
             }
 
             /* reconnect/login if expect timed out */
-            if ((dev->connect_state == DEV_CONNECTED)) {
+            if (dev->connect_state == DEV_CONNECTED) {
                 dbg(DBG_DEVICE, "_process_action: disconnecting due to error");
                 _reconnect(dev, timeout);
                 break;
