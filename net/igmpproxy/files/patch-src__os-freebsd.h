--- src/os-freebsd.h.orig	2014-10-11 14:15:20 UTC
+++ src/os-freebsd.h
@@ -14,7 +14,11 @@
 
 static inline u_short ip_data_len(const struct ip *ip)
 {
+#if __FreeBSD_version >= 900044
+	return ip->ip_len - (ip->ip_hl << 2);
+#else
 	return ip->ip_len;
+#endif
 }
 
 static inline void ip_set_len(struct ip *ip, u_short len)
