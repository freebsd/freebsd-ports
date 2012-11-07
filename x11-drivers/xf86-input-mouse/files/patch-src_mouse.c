--- src/mouse.c.orig	2012-10-18 11:06:28.000000000 +0400
+++ src/mouse.c	2012-10-18 11:06:57.000000000 +0400
@@ -872,6 +872,8 @@ MousePreInit(InputDriverPtr drv, IDevPtr
     pInfo->private_flags = 0;
     pInfo->always_core_feedback = NULL;
 
+    COLLECT_INPUT_OPTIONS(pInfo, NULL);
+
     if (NewMousePreInit(drv, pInfo, flags) == Success)
     {
         /* Check if SendDragEvents has been disabled. */
