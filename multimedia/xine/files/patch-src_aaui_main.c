--- src/aaui/main.c.orig	2008-03-23 22:52:31.000000000 +0900
+++ src/aaui/main.c	2008-03-23 22:53:32.000000000 +0900
@@ -593,7 +593,7 @@
   while ( !caca_get_event(aaxine.display, CACA_EVENT_KEY_PRESS, &ev, 50000) && aaxine.running ) ;
 
   if (!aaxine.running) return 0;
-  return ev.data.key.ch;
+  return caca_get_event_key_ch(&ev);
 #endif
 }
 
