--- src/kbd.c.orig	Wed Nov  9 22:31:23 2005
+++ src/kbd.c	Sat Oct  7 21:09:40 2006
@@ -635,7 +635,6 @@
 	      return;
   }
   
-#ifndef __sparc64__
   /*
    * PC keyboards generate separate key codes for
    * Alt+Print and Control+Pause but in the X keyboard model
@@ -648,7 +647,6 @@
     else if (scanCode == KEY_Break)
       scanCode = KEY_Pause;
   }
-#endif
 
 sunKeyboards:
   /*
