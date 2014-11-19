--- src/openfiles.cpp.orig	2011-08-30 02:46:08.000000000 +0200
+++ src/openfiles.cpp	2011-10-08 00:23:38.000000000 +0200
@@ -71,7 +71,11 @@
         goto failsafe;
 
     if (getnameinfo(res->ai_addr, res->ai_addrlen, hostname,
+#ifdef NI_IDN
                     sizeof hostname, service, sizeof service, NI_IDN))
+#else
+                    sizeof hostname, service, sizeof service, 0))
+#endif
         goto failsafe;
 
     if (res) freeaddrinfo(res);
