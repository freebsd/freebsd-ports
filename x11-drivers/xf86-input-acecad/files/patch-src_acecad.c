# Finish converting RemoveEnabledDevice to xf86RemoveEnabledDevice
#
--- src/acecad.c.orig	2016-11-24 00:26:03 UTC
+++ src/acecad.c
@@ -491,7 +491,7 @@ AceCadPreInit(InputDriverPtr drv, InputI
 
     if (local->fd != -1)
     {
-        RemoveEnabledDevice (local->fd);
+        xf86RemoveEnabledDevice (local);
         if (priv->buffer)
         {
             XisbFree(priv->buffer);
@@ -499,7 +499,7 @@ AceCadPreInit(InputDriverPtr drv, InputI
         }
         xf86CloseSerial(local->fd);
     }
-    RemoveEnabledDevice (local->fd);
+    xf86RemoveEnabledDevice (local);
     local->fd = -1;
     return Success;
 
@@ -601,7 +601,7 @@ DeviceOff (DeviceIntPtr dev)
 
     if (local->fd != -1)
     {
-        RemoveEnabledDevice (local->fd);
+        xf86RemoveEnabledDevice (local);
         if (priv->buffer)
         {
             XisbFree(priv->buffer);
