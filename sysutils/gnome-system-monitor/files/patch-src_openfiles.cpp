--- src/openfiles.cpp.orig	2023-09-02 21:02:13 UTC
+++ src/openfiles.cpp
@@ -79,7 +79,11 @@ friendlier_hostname (const char *addr_str,
     goto failsafe;
 
   if (getnameinfo (res->ai_addr, res->ai_addrlen, hostname,
+#ifdef NI_IDM
                    sizeof hostname, service, sizeof service, NI_IDN))
+#else
+                   sizeof hostname, service, sizeof service, 0))
+#endif
     goto failsafe;
 
   if (res)
