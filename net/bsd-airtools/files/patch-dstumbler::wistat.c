--- dstumbler/wistat.c.orig	Fri Jan 11 07:05:43 2002
+++ dstumbler/wistat.c	Mon Jul 21 13:27:51 2003
@@ -468,17 +468,6 @@
     return;
   }
 
-  if(scanmode)
-  {
-    setscanreq(iface);
-
-    /*
-     * some systems need the card to wait a bit before more config options are
-     * set, otherwise it could lock up the system.
-     */
-    usleep(POLLSPEED);
-  }
-
   /* first backup the current keys and encryption status */
   getcryptkeys(iface, &backup.keys);
   getcrypt(iface, &backup.crypt);
@@ -503,6 +492,17 @@
 
   /* set a null ssid for the default */
   setdefaultssid(iface, "\0");
+
+  if(scanmode)
+  {
+    setscanreq(iface);
+
+    /*
+     * some systems need the card to wait a bit before more config options are
+     * set, otherwise it could lock up the system.
+     */
+    usleep(POLLSPEED);
+  }
 
   backup.wi_started++;
 }
