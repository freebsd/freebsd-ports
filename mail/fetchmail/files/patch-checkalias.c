--- checkalias.c.orig	Thu Dec  1 00:33:18 2005
+++ checkalias.c	Sun Dec 11 14:32:33 2005
@@ -155,10 +155,11 @@
      */
     memset(&hints, 0, sizeof hints);
     hints.ai_family=AF_UNSPEC;
     hints.ai_protocol=PF_UNSPEC;
     hints.ai_socktype=SOCK_STREAM;
+    hints.ai_flags=AI_CANONNAME;
 
     e = getaddrinfo(name, NULL, &hints, &res);
     if (e == 0)
     {
 	int rr = (strcasecmp(ctl->server.truename, res->ai_canonname) == 0);
