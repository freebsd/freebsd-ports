--- networking/ping.c.orig	2021-01-01 13:30:02 UTC
+++ networking/ping.c
@@ -119,6 +119,10 @@
 //usage:       "round-trip min/avg/max = 20.1/20.1/20.1 ms\n"
 
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h> /* struct ip and friends */
+#include <netinet/ip.h>
+#endif
 #include <netinet/ip_icmp.h>
 #include "libbb.h"
 #include "common_bufsiz.h"
@@ -155,6 +159,41 @@
 #  undef IPV6_HOPLIMIT
 #  define IPV6_HOPLIMIT IPV6_2292HOPLIMIT
 # endif
+#endif
+
+#if defined(__FreeBSD__) || defined(__APPLE__)
+/**
+ * On BSD the IPv4 struct is called struct ip and instead of iXX
+ * the members are called ip_XX. One could change this code to use
+ * struct ip but that would require to define _BSD_SOURCE and that
+ * might have other complications. Instead make sure struct iphdr
+ * is present on FreeBSD. The below is taken from GLIBC.
+ *
+ * The GNU C Library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2.1 of the License, or (at your option) any later version.
+ */
+struct iphdr
+  {
+#if BYTE_ORDER == LITTLE_ENDIAN
+    unsigned int ihl:4;
+    unsigned int version:4;
+#elif BYTE_ORDER == BIG_ENDIAN
+    unsigned int version:4;
+    unsigned int ihl:4;
+#endif
+    u_int8_t tos;
+    u_int16_t tot_len;
+    u_int16_t id;
+    u_int16_t frag_off;
+    u_int8_t ttl;
+    u_int8_t protocol;
+    u_int16_t check;
+    u_int32_t saddr;
+    u_int32_t daddr;
+    /*The options start here. */
+  };
 #endif
 
 enum {
