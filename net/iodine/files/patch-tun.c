--- src/tun.c.orig	2009-12-10 20:26:35.000000000 -0800
+++ src/tun.c	2009-12-10 20:26:46.000000000 -0800
@@ -402,10 +402,9 @@
 	}
 #ifndef WINDOWS32
 	snprintf(cmdline, sizeof(cmdline), 
-			"/sbin/ifconfig %s %s %s netmask %s",
+			"/sbin/ifconfig %s %s netmask %s",
 			if_name,
 			ip,
-			ip,
 			inet_ntoa(net));
 	
 	fprintf(stderr, "Setting IP of %s to %s\n", if_name, ip);
