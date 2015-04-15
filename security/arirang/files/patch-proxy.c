Do not attempt to close the sock we never opened. Use herror() to report
a DNS-failure, not perror().

	-mi

--- proxy.c	2011-05-17 22:19:11.000000000 -0400
+++ proxy.c	2015-03-23 09:46:34.000000000 -0400
@@ -94,15 +94,13 @@
     struct hostent *he;
 
     if ((he = gethostbyname(proxyhost)) == NULL) {
-        perror("proxy host not found");
-        close(sock);  
+        herror("proxy host not found");
         exit(0);
     }
 
 
     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
         perror("socket");
-        close(sock);
         exit(0);
     }
     http.sin_family = AF_INET;
