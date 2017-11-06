Do not attempt to close the sock we never opened. Use herror() to report
a DNS-failure, not perror().

	-mi

--- proxy.c.orig	2011-05-18 02:19:11 UTC
+++ proxy.c
@@ -94,15 +94,13 @@ proxy_connect(char *scanhost, unsigned i
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
