--- conffile.c.orig	2016-06-20 14:44:21 UTC
+++ conffile.c
@@ -57,6 +57,7 @@ do_something_with (char *ip, char *url)
 	struct hostent *h;
 	char *addy;
 	int port;
+	char *tport;
 
 	if (ip && url)
 	{
@@ -70,7 +71,7 @@ do_something_with (char *ip, char *url)
 		else
 		{
 			strtok(ip,":");
-			char *tport = strtok(NULL,":");
+			tport = strtok(NULL,":");
 			port = atoi(tport);
 		}
 /*
