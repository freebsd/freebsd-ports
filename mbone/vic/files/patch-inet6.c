--- net/inet6.c.org	Mon Feb  4 17:51:32 2002
+++ net/inet6.c	Mon Feb  4 17:52:02 2002
@@ -64,11 +64,7 @@
     memcpy(addr->s6_addr, &(((struct sockaddr_in6 *)(ai->ai_addr))->sin6_addr),  sizeof(struct in6_addr));
     return (0);
 #else
-#ifdef MUSICA_IPV6
     hp = gethostbyname2(hostname, AF_INET6);
-#else
-    hp = getnodebyname(hostname, AF_INET6,AI_DEFAULT);
-#endif /*MUSICA_IPV6*/
 #endif /*LINUX_IPV6*/
 #endif /*SOLARIS7_IPV6*/
     if (hp == 0)  return (-1);
