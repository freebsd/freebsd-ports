--- nasl/nasl_builtin_openvas_tcp_scanner.c.orig	2015-08-03 10:14:31 UTC
+++ nasl/nasl_builtin_openvas_tcp_scanner.c
@@ -473,7 +473,7 @@ banner_grab(const struct in6_addr *pia, 
 #endif
         if(IN6_IS_ADDR_V4MAPPED(pia))
         {
-          sa.sin_addr.s_addr = pia->s6_addr32[3];
+          memcpy(&sa.sin_addr.s_addr, &pia->s6_addr[12], 4);
           sa.sin_family = AF_INET;
           sa.sin_port = htons(port);
           len = sizeof(struct sockaddr_in);
