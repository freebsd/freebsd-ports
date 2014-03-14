--- ./src/drv_imap.c.orig	2013-12-15 13:46:06.000000000 +0100
+++ ./src/drv_imap.c	2014-03-10 17:37:57.715669758 +0100
@@ -835,11 +835,11 @@
 	memset( &datetime, 0, sizeof(datetime) );
 	if (!(end = strptime( str, "%d-%b-%Y %H:%M:%S ", &datetime )))
 		return -1;
-	if ((date = mktime( &datetime )) == -1)
+	if ((date = timegm( &datetime )) == -1)
 		return -1;
 	if (sscanf( end, "%3d%2d", &hours, &mins ) != 2)
 		return -1;
-	return date - (hours * 60 + mins) * 60 - timezone;
+	return date - (hours * 60 + mins) * 60;
 }
 
 static int
