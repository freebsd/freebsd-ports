--- src/parse.y.orig	2017-08-11 19:19:57 UTC
+++ src/parse.y
@@ -136,6 +136,8 @@ main		: LISTEN ON address listen_opts	{
 			struct sockaddr_in sin4;
 			struct sockaddr_in6 sin6;
 
+			memset(&sin4, 0, sizeof(sin4));
+			memset(&sin6, 0, sizeof(sin6));
 			sin4.sin_family = AF_INET;
 			sin6.sin6_family = AF_INET6;
 #ifdef HAVE_STRUCT_SOCKADDR_IN_SIN_LEN
@@ -144,9 +146,9 @@ main		: LISTEN ON address listen_opts	{
 #endif
 
 			if (inet_pton(AF_INET, $3, &sin4.sin_addr) == 1)
-				memcpy(&query_addr4, &sin4, sizeof(struct in_addr));
+				memcpy(&query_addr4, &sin4, sizeof(struct sockaddr_in));
 			else if (inet_pton(AF_INET6, $3, &sin6.sin6_addr) == 1)
-				memcpy(&query_addr6, &sin6, sizeof(struct in6_addr));
+				memcpy(&query_addr6, &sin6, sizeof(struct sockaddr_in6));
 			else {
 				yyerror("invalid IPv4 or IPv6 address: %s\n",
 				    $3);
