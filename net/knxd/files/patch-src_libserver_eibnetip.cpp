--- src/libserver/eibnetip.cpp.orig	2020-02-11 20:13:04 UTC
+++ src/libserver/eibnetip.cpp
@@ -192,7 +192,11 @@ EIBNetIPSocket::port ()
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
