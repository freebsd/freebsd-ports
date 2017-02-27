--- src/Mayaqua/Kernel.c.orig	2016-05-03 06:16:53 UTC
+++ src/Mayaqua/Kernel.c
@@ -2213,7 +2213,7 @@ void AbortExitEx(char *msg)
 		msg = "Unknown Error";
 	}
 
-	f = fopen("abort_error_log.txt", "w");
+	f = fopen("/var/db/softether/abort_error_log.txt", "w");
 	if (f != NULL)
 	{
 		fwrite(msg, 1, strlen(msg), f);
