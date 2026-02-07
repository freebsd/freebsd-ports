--- nasl/nasl_builtin_openvas_tcp_scanner.c	2020-12-31 17:19:06.511436000 -0500
+++ nasl/nasl_builtin_openvas_tcp_scanner.c	2020-12-31 17:20:31.824455000 -0500
@@ -428,7 +428,7 @@
               bzero (&sa6, sizeof (sa6));
               if (IN6_IS_ADDR_V4MAPPED (pia))
                 {
-                  sa.sin_addr.s_addr = pia->s6_addr32[3];
+                  sa.sin_addr.s_addr = pia->s6_addr[12];
                   sa.sin_family = AF_INET;
                   sa.sin_port = htons (port);
                   len = sizeof (struct sockaddr_in);
