--- src/toss/ftntoss.c.orig	Mon Jan 29 12:53:14 2007
+++ src/toss/ftntoss.c	Mon Jan 29 12:53:22 2007
@@ -882,7 +882,7 @@
 #endif /* !SECURITY */
 
     if (NULL != (pwd = passwd_lookup("packet", &msg->node_from)) &&
-	!stricmp(pkt->passwd, pwd->passwd))
+	stricmp(pkt->passwd, pwd->passwd))
     {
 	fglog("Insecure echomail packet from %s, area %s (%s pkt password)",
 	      znfp1(&msg->node_from), areaname,
