--- ./HttpHandler.cpp.orig	2008-08-23 04:00:12.000000000 -0700
+++ ./HttpHandler.cpp	2011-12-30 17:37:16.000000000 -0800
@@ -427,7 +427,7 @@
 
 void HttpHandler::putline(const string& line)
 {
-	sprintf(buffer, "%s\r\n", line.c_str());
+	snprintf(buffer, BUFSIZ + 1, "%s\r\n", line.c_str());
 
 #ifndef _OpenSSL_
 	if (send(http, buffer, strlen(buffer), 0) == SOCKET_ERROR)
