--- main/utils.c.orig	2016-11-23 15:26:01 UTC
+++ main/utils.c
@@ -2425,6 +2425,18 @@ char *ast_utils_which(const char *binary
 	return NULL;
 }
 
+int ast_check_ipv6(void)
+{
+	int udp6_socket = socket(AF_INET6, SOCK_DGRAM, 0);
+
+	if (udp6_socket < 0) {
+		return 0;
+	}
+
+	close(udp6_socket);
+	return 1;
+}
+
 void DO_CRASH_NORETURN ast_do_crash(void)
 {
 #if defined(DO_CRASH)
