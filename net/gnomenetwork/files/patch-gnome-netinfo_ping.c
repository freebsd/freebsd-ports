--- gnome-netinfo/ping.c.orig	Sat Dec  6 23:08:52 2003
+++ gnome-netinfo/ping.c	Sat Dec  6 23:17:35 2003
@@ -330,6 +330,8 @@
 
 	if (netinfo_get_ip_version (netinfo) == IPV4)
 		line = g_strdelimit (line, ":", ' ');
+	else
+	    	line = g_strdelimit (line, ",", ' ');
 
 #ifdef PING_PARAMS_5
 	count = sscanf (line, PING_FORMAT,
