--- main.c.orig	2013-06-19 11:23:58 UTC
+++ main.c
@@ -608,7 +608,8 @@ tun2raw(struct connection *c)
 	ip4 = (struct ipv4_header *)(buf - sizeof(*ip4));
 	ip4->ver_hlen = 4 << 4 | sizeof(*ip4) >> 2;
 	ip4->tos = ntohl(ip6->ver_class_label) >> 20 & 0xff;
-#if defined(__OpenBSD__) || defined(__linux__)
+#if defined(__OpenBSD__) || defined(__linux__) || \
+    (defined(__FreeBSD__) && __FreeBSD_version >= 1100030)
 	ip4->len = htons(len + sizeof(*ip4));
 #else
 	ip4->len = len + sizeof(*ip4);
