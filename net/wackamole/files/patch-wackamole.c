--- wackamole.c.orig	2011-05-12 02:43:02.000000000 +0200
+++ wackamole.c	2011-05-12 02:46:20.000000000 +0200
@@ -911,7 +911,7 @@
       wack_alarm(PRINT, "%d %s", __LINE__, if_error());
     else {
       char buffer[16];
-      snprintf(buffer, 16, inet_ntoa(iface.ipaddr));
+      snprintf(buffer, 16, "%s", inet_ntoa(iface.ipaddr));
       wack_alarm(PRINT, "  UP: %s:%s/%s",
 		iface.ifname,buffer,inet_ntoa(iface.netmask));
     }
@@ -954,7 +954,7 @@
       }
     } else {
       char buffer[16];
-      snprintf(buffer, 16, inet_ntoa(idown.ipaddr));
+      snprintf(buffer, 16, "%s", inet_ntoa(idown.ipaddr));
       wack_alarm(PRINT, "DOWN: %s:%s/%s",
 	idown.ifname,buffer,inet_ntoa(idown.netmask));
     }
