--- src/os-freebsd.h.orig	2009-10-06 02:07:06.000000000 +0800
+++ src/os-freebsd.h	2016-01-20 15:43:54.364740000 +0800
@@ -14,10 +14,20 @@
 
 static inline u_short ip_data_len(const struct ip *ip)
 {
+#if __FreeBSD_version >= 1100030
+	return ntohs(ip->ip_len) - (ip->ip_hl << 2);
+#elif __FreeBSD_version >= 900044
+	return ip->ip_len - (ip->ip_hl << 2);
+#else
 	return ip->ip_len;
+#endif
 }
 
 static inline void ip_set_len(struct ip *ip, u_short len)
 {
+#if __FreeBSD_version >= 1100030
+	ip->ip_len = htons(len);
+#else
 	ip->ip_len = len;
+#endif
 }
