--- proxychains/core.h.orig	2006-03-15 16:16:59 UTC
+++ proxychains/core.h
@@ -68,27 +68,27 @@ struct hostent* proxy_gethostbyname(const char *name);
 
 
 typedef int (*connect_t)(int, const struct sockaddr *, socklen_t);
-connect_t true_connect;
+extern connect_t true_connect;
 
 typedef struct hostent* (*gethostbyname_t)(const char *);
-gethostbyname_t true_gethostbyname;
+extern gethostbyname_t true_gethostbyname;
 
 typedef int (*getaddrinfo_t)(const char *, const char *,
 		const struct addrinfo *,
 		struct addrinfo **);
-getaddrinfo_t true_getaddrinfo;
+extern getaddrinfo_t true_getaddrinfo;
 
 typedef int (*freeaddrinfo_t)(struct addrinfo *);
-freeaddrinfo_t true_freeaddrinfo;
+extern freeaddrinfo_t true_freeaddrinfo;
 
 typedef int (*getnameinfo_t) (const struct sockaddr *,
 		socklen_t, char *,
 		socklen_t, char *,
 		socklen_t, unsigned int);
-getnameinfo_t true_getnameinfo;
+extern getnameinfo_t true_getnameinfo;
 
 typedef struct hostent *(*gethostbyaddr_t) (const void *, socklen_t, int);
-gethostbyaddr_t true_gethostbyaddr;
+extern gethostbyaddr_t true_gethostbyaddr;
 
 int proxy_getaddrinfo(const char *node, const char *service,
 		                const struct addrinfo *hints,
