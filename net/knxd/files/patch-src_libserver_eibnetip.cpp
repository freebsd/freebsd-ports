--- src/libserver/eibnetip.cpp.orig	2019-07-26 22:23:32 UTC
+++ src/libserver/eibnetip.cpp
@@ -248,7 +248,11 @@ EIBNetIPSocket::port ()
     return -1;
   if (sa.sin_family != AF_INET)
     {
+#ifdef ENODATA
       errno = ENODATA;
+#else
+      errno = 9919;
+#endif
       return -1;
     }
   return sa.sin_port;
