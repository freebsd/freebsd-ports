Index: programs/Xserver/hw/xfree86/drivers/trident/trident_video.c
===================================================================
RCS file: /usr/local/repos/xfree86/xc/programs/Xserver/hw/xfree86/drivers/trident/trident_video.c,v
retrieving revision 1.47
retrieving revision 1.48
diff -u -r1.47 -r1.48
--- programs/Xserver/hw/xfree86/drivers/trident/trident_video.c	29 Mar 2004 16:25:22 -0000	1.47
+++ programs/Xserver/hw/xfree86/drivers/trident/trident_video.c	30 Apr 2005 17:04:00 -0000	1.48
@@ -1307,6 +1307,8 @@
      * full vblank has passed. 
      * - Alan.
      */
-    WAITFORVSYNC;
-    WAITFORVSYNC;
+    if (!xf86IsPc98()) {
+       WAITFORVSYNC;
+       WAITFORVSYNC;
+    }
 }
