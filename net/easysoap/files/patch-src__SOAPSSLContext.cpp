--- src/SOAPSSLContext.cpp.orig
+++ src/SOAPSSLContext.cpp
@@ -143,16 +143,16 @@
         switch(methodType)
         {
         case SOAPSSLContext::SSL_v2:
-                method = SSLv2_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv2_client_method());
                 break;
         case SOAPSSLContext::SSL_v23:
-                method = SSLv23_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv23_client_method());
                 break; 
         case SOAPSSLContext::SSL_v3:
-                method = SSLv3_client_method();
+                method = const_cast<SSL_METHOD*>(SSLv3_client_method());
                 break; 
         case SOAPSSLContext::TLS_v1:
-                method = TLSv1_client_method();
+                method = const_cast<SSL_METHOD*>(TLSv1_client_method());
                 break; 
         default:
                 break;
