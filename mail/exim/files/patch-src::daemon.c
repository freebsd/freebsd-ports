--- src/daemon.c.orig	Tue Jul 10 11:52:32 2001
+++ src/daemon.c	Tue Jul 10 11:53:33 2001
@@ -841,7 +841,8 @@
 
     for (i = 9; i >= 0; i--)
       {
-      if (bind(listen_sockets[sk], (struct sockaddr *)&sin, sizeof(sin)) < 0)
+      if (bind(listen_sockets[sk], (struct sockaddr *)&sin,
+         (ipv6_address) ? sizeof(sin.v6) : sizeof(sin.v4)) < 0)
         {
         char *msg = strerror(errno);
         char *addr = (ipa->address[0] == 0)? "(any)" : ipa->address;
