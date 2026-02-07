--- sdk/src/http.cpp.orig	2024-05-17 14:19:43 UTC
+++ sdk/src/http.cpp
@@ -270,7 +270,11 @@ void HttpIO::getMEGADNSservers(string *dnsservers, boo
         hints.ai_family = AF_UNSPEC;
 
 #ifndef __MINGW32__
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+        hints.ai_flags = AI_ADDRCONFIG;
+#else
         hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+#endif
 #endif
 
         if (!getaddrinfo("ns.mega.co.nz", NULL, &hints, &aiList))
