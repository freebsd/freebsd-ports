--- plugins/check_http.c.orig	Mon Jun 30 11:56:08 2003
+++ plugins/check_http.c	Fri Dec 19 23:03:52 2003
@@ -198,3 +198,3 @@
 
-char timestamp[17] = "";
+char timestamp[256] = "";
 int specify_port = FALSE;
@@ -975,3 +975,3 @@
 	snprintf
-		(timestamp, 16, "%02d/%02d/%04d %02d:%02d",
+		(timestamp, sizeof(timestamp), "%02d/%02d/%04d %02d:%02d",
 		 stamp.tm_mon + 1,
