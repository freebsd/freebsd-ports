--- programs/Xserver/hw/xfree86/common/xf86Events.c.orig	Wed May 21 14:24:03 2003
+++ programs/Xserver/hw/xfree86/common/xf86Events.c	Wed May 21 14:24:28 2003
@@ -828,6 +828,7 @@
     }
 #endif
 
+#ifndef __sparc64__
   /*
    * PC keyboards generate separate key codes for
    * Alt+Print and Control+Pause but in the X keyboard model
@@ -838,6 +839,7 @@
     scanCode = KEY_Print;
   else if (scanCode == KEY_Break)
     scanCode = KEY_Pause;
+#endif
   
   /*
    * Now map the scancodes to real X-keycodes ...
