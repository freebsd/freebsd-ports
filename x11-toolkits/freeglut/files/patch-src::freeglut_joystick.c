--- src/freeglut_joystick.c.orig	Wed May  4 14:53:48 2005
+++ src/freeglut_joystick.c	Sat Jun 11 14:40:48 2005
@@ -80,7 +80,7 @@
 /* XXX The below hack is done until freeglut's autoconf is updated. */
 #        define HAVE_USB_JS    1
 
-#        if defined(__FreeBSD__) && __FreeBSD_version >= 500000
+#        if defined(__FreeBSD__)
 #            include <sys/joystick.h>
 #        else
 /*
@@ -656,9 +656,9 @@
                if (usage > 0 && usage < _JS_MAX_BUTTONS + 1)
                {
                    if (d)
-                       joy->os->cache_buttons |= (1 << usage - 1);
+                       joy->os->cache_buttons |= (1 << (usage - 1));
                    else
-                       joy->os->cache_buttons &= ~(1 << usage - 1);
+                       joy->os->cache_buttons &= ~(1 <<( usage - 1));
                }
             }
         }
@@ -1060,7 +1060,9 @@
 #    ifdef JS_NEW
        unsigned char u;
 #    else
-       int counter;
+#      if defined( __linux__ )
+         int counter;
+#      endif
 #    endif
 #endif
 
