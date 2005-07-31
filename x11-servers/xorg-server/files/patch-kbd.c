Index: programs/Xserver/hw/xfree86/input/keyboard/kbd.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/input/keyboard/kbd.c,v
retrieving revision 1.15
retrieving revision 1.16
diff -u -r1.15 -r1.16
--- programs/Xserver/hw/xfree86/input/keyboard/kbd.c	11 Jul 2005 02:38:00 -0000	1.15
+++ programs/Xserver/hw/xfree86/input/keyboard/kbd.c	13 Jul 2005 12:30:04 -0000	1.16
@@ -553,6 +553,19 @@
   if (xf86inSuspend)
       return;
 
+  if (pKbd->sunKbd) {
+     /*
+      * XXX XXX XXX:
+      *
+      * I really don't know what's wrong here, but passing the real
+      * scanCode offsets by one from XKB's point of view.
+      *
+      * (ecd@skynet.be, 980405)
+      */
+      scanCode--;
+      goto sunKeyboards;
+  }
+
   /*
    * First do some special scancode remapping ...
    */
@@ -616,6 +629,7 @@
   }
 #endif
 
+sunKeyboards:
   /*
    * Now map the scancodes to real X-keycodes ...
    */
