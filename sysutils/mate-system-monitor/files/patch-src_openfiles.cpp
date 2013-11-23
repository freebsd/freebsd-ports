--- src/openfiles.cpp.orig	2008-05-27 16:16:46.000000000 -0400
+++ src/openfiles.cpp	2008-05-27 16:19:53.000000000 -0400
@@ -66,7 +66,11 @@ friendlier_hostname(const char *addr_str
 		goto failsafe;
 
 	if (getnameinfo(res->ai_addr, res->ai_addrlen, hostname,
+#ifdef NI_IDN
 			sizeof hostname, service, sizeof service, NI_IDN))
+#else
+	    		sizeof hostname, service, sizeof service, 0))
+#endif
 		goto failsafe;
 
 	if (res) freeaddrinfo(res);
