Index: server/vino-http.c
diff -u -p server/vino-http.c.orig server/vino-http.c
--- server/vino-http.c.orig	Tue Feb 27 19:47:35 2007
+++ server/vino-http.c	Sun Mar 25 20:56:41 2007
@@ -595,6 +595,9 @@ vino_http_create_listening_socket (VinoH
 {
 #ifdef ENABLE_IPV6
   struct sockaddr_in6  saddr_in6;
+#ifdef IPV6_V6ONLY
+  int                  off = 0;
+#endif
 #endif
   struct sockaddr_in   saddr_in;
   struct sockaddr     *saddr;
@@ -621,6 +624,9 @@ vino_http_create_listening_socket (VinoH
 
 #ifdef ENABLE_IPV6
   sock = socket (AF_INET6, SOCK_STREAM, 0);
+#ifdef IPV6_V6ONLY
+  setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof(off));
+#endif
 
   memset (&saddr_in6, 0, sizeof (struct sockaddr_in6));
   saddr_in6.sin6_family = AF_INET6;
