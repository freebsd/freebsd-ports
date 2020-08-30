--- proxychains/core.c.orig	2020-08-30 09:26:56 UTC
+++ proxychains/core.c
@@ -41,6 +41,13 @@ extern int tcp_read_time_out;
 extern int tcp_connect_time_out;
 extern int proxychains_quiet_mode;
 
+connect_t true_connect;
+gethostbyname_t true_gethostbyname;
+getaddrinfo_t true_getaddrinfo;
+freeaddrinfo_t true_freeaddrinfo;
+getnameinfo_t true_getnameinfo;
+gethostbyaddr_t true_gethostbyaddr;
+
 static const char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
 static void encode_base_64(char* src,char* dest,int max_len)
