--- programs/Xserver/hw/xfree86/common/xf86Events.c.orig	Mon Aug 25 04:08:11 2003
+++ programs/Xserver/hw/xfree86/common/xf86Events.c	Wed Sep 17 19:38:22 2003
@@ -627,6 +627,7 @@
       scanCode = KEY_Pause;       /* pause */
     }
 
+#ifndef __sparc64__
   /*
    * PC keyboards generate separate key codes for
    * Alt+Print and Control+Pause but in the X keyboard model
@@ -637,6 +638,7 @@
     scanCode = KEY_Print;
   else if (scanCode == KEY_Break)
     scanCode = KEY_Pause;
+#endif
   
   /*
    * and now get some special keysequences
