--- nx-X11/programs/Xserver/hw/nxagent/Reconnect.c.orig	Sat Sep 11 16:04:08 2004
+++ nx-X11/programs/Xserver/hw/nxagent/Reconnect.c	Sat Sep 11 16:04:23 2004
@@ -308,7 +308,7 @@
   while (sessionState == SESSION_SLEEPING)
   {
     /* Blocking SIG_ALRM. */
-    pselect(0, NULL, NULL, NULL, NULL, &sleep_set); 
+    select(0, NULL, NULL, NULL, &sleep_set); 
   }
 
   if (sessionState == SESSION_TERM)
