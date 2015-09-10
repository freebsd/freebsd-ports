--- src/Mayaqua/Kernel.c.orig	2014-06-08 06:19:14 UTC
+++ src/Mayaqua/Kernel.c
@@ -2160,7 +2160,7 @@
 		msg = "Unknown Error";
 	}
 
-	f = fopen("abort_error_log.txt", "w");
+	f = fopen("/var/db/softether/abort_error_log.txt", "w");
 	if (f != NULL)
 	{
 		fwrite(msg, 1, strlen(msg), f);
