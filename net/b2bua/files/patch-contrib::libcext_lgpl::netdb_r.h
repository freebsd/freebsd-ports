
$FreeBSD$

--- contrib/libcext_lgpl/netdb_r.h
+++ contrib/libcext_lgpl/netdb_r.h
@@ -2,6 +2,7 @@
 extern "C" {
 #endif
 
+#if !defined(__FreeBSD__)
 struct hostent *
 gethostbyaddr_r (const char *addr, int length, int type,
        struct hostent *result, char *buffer, int buflen,
@@ -15,6 +16,7 @@
 struct hostent *
 gethostent_r (struct hostent *result, char *buffer, int buflen,
        int *h_errnop);
+#endif
 
 #ifdef __cplusplus
 }
