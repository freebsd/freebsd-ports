--- net.c.orig	2001-04-06 16:36:25.000000000 +0800
+++ net.c	2011-09-06 11:35:01.000000000 +0800
@@ -9,6 +9,7 @@ proxy_t				proxy = {NULL, 8000};
 /*----------------------------------------------------------------*/
 int setup_socket(char *host, int port)
 {
+	struct in_addr addr;
 	unsigned long start;
 	unsigned long end;
 	unsigned long counter;
@@ -24,8 +25,8 @@ int setup_socket(char *host, int port)
 	}
 
 	//start   = inet_addr(host);
-	inet_aton(host, &start);		// rather than inet_addr, etc.
-	counter = ntohl(start);
+	inet_aton(host, &addr);		// rather than inet_addr, etc.
+	counter = ntohl(addr.s_addr);
 
 	sock = socket(AF_INET, SOCK_STREAM, 0);
 	bcopy(he->h_addr, (char *) &_sin.sin_addr, he->h_length);
@@ -150,10 +151,10 @@ int http_has(char *file, int result)
     {
 		if (parms.no_false_200_search == FALSE)
 		{
-			if (strnstr(httpbuff, "file not found") ||
-				strnstr(httpbuff, "error 404") ||
-				strnstr(httpbuff, "document has moved") ||
-				strnstr(httpbuff, "page you have requested") ) // Wise?
+			if (cgichk_strnstr(httpbuff, "file not found") ||
+				cgichk_strnstr(httpbuff, "error 404") ||
+				cgichk_strnstr(httpbuff, "document has moved") ||
+				cgichk_strnstr(httpbuff, "page you have requested") ) // Wise?
 			{
 				err = HTTP_NOEXIST;
 			}
@@ -161,7 +162,7 @@ int http_has(char *file, int result)
 			// If user spcified an additional string to search for, check for that too.
 			if (parms.alt_fake_404_string)
 			{
-				if (strnstr(httpbuff, parms.alt_fake_404_string))
+				if (cgichk_strnstr(httpbuff, parms.alt_fake_404_string))
 				{
 					err = HTTP_NOEXIST;
 				}
