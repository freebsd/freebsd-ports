--- src/ssl/support.cc.orig	2015-09-01 21:52:00.000000000 +0200
+++ src/ssl/support.cc	2015-09-10 14:54:11.904525425 +0200
@@ -1070,8 +1070,13 @@ Ssl::method(int version)
         break;
 
     case 3:
+#ifndef OPENSSL_NO_SSL3
         debugs(83, 5, "Using SSLv3.");
         return SSLv3_client_method();
+#else
+        debugs(83, DBG_IMPORTANT, "SSLv3 is not available in this Proxy.");
+        return NULL;
+#endif
         break;
 
     case 4:
@@ -1127,8 +1132,13 @@ Ssl::serverMethod(int version)
         break;
 
     case 3:
+#ifndef OPENSSL_NO_SSL3
         debugs(83, 5, "Using SSLv3.");
         return SSLv3_server_method();
+#else
+        debugs(83, DBG_IMPORTANT, "SSLv3 is not available in this Proxy.");
+        return NULL;
+#endif
         break;
 
     case 4:
@@ -1563,8 +1563,13 @@ Ssl::contextMethod(int version)
         break;
 
     case 3:
+#ifndef OPENSSL_NO_SSL3
         debugs(83, 5, "Using SSLv3.");
         method = SSLv3_server_method();
+#else
+        debugs(83, DBG_IMPORTANT, "SSLv3 is not available in this Proxy.");
+        return NULL;
+#endif
         break;
 
     case 4:
