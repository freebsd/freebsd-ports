--- plugins/check_http.c.orig	Mon Sep 15 07:03:47 2003
+++ plugins/check_http.c	Sat Nov 27 12:32:09 2004
@@ -83,7 +83,7 @@
 #define HTTP_URL "/"
 #define CRLF "\r\n"
 
-char timestamp[17] = "";
+char timestamp[256] = "";
 int specify_port = FALSE;
 int server_port = HTTP_PORT;
 char server_port_text[6] = "";
@@ -1010,7 +1010,7 @@
 
 	days_left = (mktime (&stamp) - time (NULL)) / 86400;
 	snprintf
-		(timestamp, 17, "%02d/%02d/%04d %02d:%02d",
+		(timestamp, sizeof(timestamp), "%02d/%02d/%04d %02d:%02d",
 		 stamp.tm_mon + 1,
 		 stamp.tm_mday, stamp.tm_year + 1900, stamp.tm_hour, stamp.tm_min);
 
