--- bozohttpd.h.orig	2024-02-04 05:55:04 UTC
+++ bozohttpd.h
@@ -130,7 +130,7 @@ typedef struct bozohttpd_t {
 	unsigned	ssl_timeout;	/* ssl timeout */
 	unsigned	initial_timeout;/* first line timeout */
 	unsigned	header_timeout;	/* header lines timeout */
-	unsigned	request_timeout;/* total session timeout */
+	int		request_timeout;/* total session timeout */
 	char		*ssl_min_proto;	/* minimum ssl protocol level */
 #ifndef NO_LUA_SUPPORT
 	int		 process_lua;	/* use the Lua handler */
