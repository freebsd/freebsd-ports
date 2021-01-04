--- networking/httpd.c.orig	2021-01-01 13:30:02 UTC
+++ networking/httpd.c
@@ -267,6 +267,11 @@
 
 #define HEADER_READ_TIMEOUT 60
 
+/* see sys/netinet6/in6.h */
+#ifdef __FreeBSD__
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
+
 static const char DEFAULT_PATH_HTTPD_CONF[] ALIGN1 = "/etc";
 static const char HTTPD_CONF[] ALIGN1 = "httpd.conf";
 static const char HTTP_200[] ALIGN1 = "HTTP/1.0 200 OK\r\n";
