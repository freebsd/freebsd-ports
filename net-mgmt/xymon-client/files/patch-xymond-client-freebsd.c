--- xymond/client/freebsd.c.orig	2013-07-24 08:04:37.846706826 -0500
+++ xymond/client/freebsd.c	2013-07-24 08:04:47.559598756 -0500
@@ -47,7 +47,7 @@
 
 	timestr = getdata("date");
 	uptimestr = getdata("uptime");
-	clockstr = getdata("clockstr");
+	clockstr = getdata("clock");
 	msgcachestr = getdata("msgcache");
 	whostr = getdata("who");
 	psstr = getdata("ps");
