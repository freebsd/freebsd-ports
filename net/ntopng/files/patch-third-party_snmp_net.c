--- third-party/snmp/net.c.orig	2018-01-12 09:48:20 UTC
+++ third-party/snmp/net.c
@@ -64,7 +64,7 @@ int open_udp_socket(int port)
   si_me.sin_family = AF_INET;
   si_me.sin_port = htons(port);
   si_me.sin_addr.s_addr = htonl(INADDR_ANY);
-  if (bind(s, (struct sockaddr *) &si_me, sizeof(si_me)) != 0)
+  if (::bind(s, (struct sockaddr *) &si_me, sizeof(si_me)) != 0)
     return(-1); //diep("bind");
     
   return s;
