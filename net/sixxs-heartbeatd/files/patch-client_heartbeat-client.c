
$FreeBSD$

--- client/heartbeat-client.c.orig	Fri Apr 23 22:00:57 2004
+++ client/heartbeat-client.c	Fri Apr 23 22:01:14 2004
@@ -277,7 +277,7 @@
 	if (argc != 2)
 	{
 		fprintf(stderr,
-			"heartbeat-client <configfile>\n");
+			"sixxs-heartbeatd <configfile>\n");
 		return -1;
 	}
 
