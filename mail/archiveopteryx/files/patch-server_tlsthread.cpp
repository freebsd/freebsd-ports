--- server/tlsthread.cpp.orig	2017-01-10 15:10:07 UTC
+++ server/tlsthread.cpp
@@ -93,7 +93,7 @@ void TlsThread::setup()
     SSL_library_init();
 
     ctx = ::SSL_CTX_new( SSLv23_server_method() );
-    int options = SSL_OP_ALL
+    long options = SSL_OP_ALL
                   // also try to pick the same ciphers suites more often
                   | SSL_OP_CIPHER_SERVER_PREFERENCE
                   // and don't use SSLv2, even if the client wants to
