--- base/openvas_networking.c.orig	2015-12-08 07:07:23 UTC
+++ base/openvas_networking.c
@@ -38,13 +38,13 @@
  /* Global variables */
 
 /* Source interface name eg. eth1. */
-char global_source_iface[IFNAMSIZ] = { '\0' };
+char global_source_iface[IFNAMSIZ];
 
 /* Source IPv4 address. */
-struct in_addr global_source_addr = { .s_addr = 0 };
+struct in_addr global_source_addr;
 
 /* Source IPv6 address. */
-struct in6_addr global_source_addr6 = { .s6_addr32 = { 0, 0, 0, 0 } };
+struct in6_addr global_source_addr6;
 
  /* Source Interface/Address related functions. */
 
@@ -230,10 +230,19 @@ ipv4_as_ipv6 (const struct in_addr *ip4,
   if (ip4 == NULL || ip6 == NULL)
     return;
 
-  ip6->s6_addr32[0] = 0;
-  ip6->s6_addr32[1] = 0;
-  ip6->s6_addr32[2] = htonl (0xffff);
-  memcpy (&ip6->s6_addr32[3], ip4, sizeof (struct in_addr));
+  ip6->s6_addr[0] = 0;
+  ip6->s6_addr[1] = 0;
+  ip6->s6_addr[2] = 0;
+  ip6->s6_addr[3] = 0;
+  ip6->s6_addr[4] = 0;
+  ip6->s6_addr[5] = 0;
+  ip6->s6_addr[6] = 0;
+  ip6->s6_addr[7] = 0;
+  ip6->s6_addr[8] = 0;
+  ip6->s6_addr[9] = 0;
+  ip6->s6_addr[10] = 0xff;
+  ip6->s6_addr[11] = 0xff;
+  memcpy (&ip6->s6_addr[12], ip4, sizeof (struct in_addr));
 }
 
 char *
@@ -246,7 +255,7 @@ addr6_as_str (const struct in6_addr *add
 
   str = g_malloc0 (INET6_ADDRSTRLEN);
   if (IN6_IS_ADDR_V4MAPPED (addr6))
-    inet_ntop (AF_INET, &addr6->s6_addr32[3], str, INET6_ADDRSTRLEN);
+    inet_ntop (AF_INET, &addr6->s6_addr[12], str, INET6_ADDRSTRLEN);
   else
     inet_ntop (AF_INET6, addr6, str, INET6_ADDRSTRLEN);
   return str;
