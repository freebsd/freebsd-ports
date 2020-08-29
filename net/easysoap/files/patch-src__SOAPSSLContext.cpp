--- src/SOAPSSLContext.cpp.orig	2005-09-24 07:24:24 UTC
+++ src/SOAPSSLContext.cpp
@@ -142,17 +142,21 @@ SSL_METHOD* SOAPSSLContext::getMethod(Me
 
         switch(methodType)
         {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(OPENSSL_NO_SSL2)
         case SOAPSSLContext::SSL_v2:
-                method = SSLv2_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv2_client_method());
                 break;
+#endif
         case SOAPSSLContext::SSL_v23:
-                method = SSLv23_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv23_client_method());
                 break; 
+#ifndef OPENSSL_NO_SSL3_METHOD
         case SOAPSSLContext::SSL_v3:
-                method = SSLv3_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv3_client_method());
                 break; 
+#endif
         case SOAPSSLContext::TLS_v1:
-                method = TLSv1_client_method();
+                method = const_cast<SSL_METHOD*>(TLSv1_client_method());
                 break; 
         default:
                 break;
