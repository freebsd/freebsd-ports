--- src/tlsgnutlsclient.cpp.orig
+++ src/tlsgnutlsclient.cpp
@@ -18,12 +18,6 @@
 
 #include <errno.h>
 
-#ifdef HAVE_PTHREAD
-extern "C" {
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
-}
-#endif
-
 namespace gloox
 {
 
@@ -48,8 +42,6 @@
                            const std::string& /*clientCerts*/,
                            const StringList& /*cacerts*/ )
   {
-    gcry_control( GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread );
-
     const int protocolPriority[] = {
 #ifdef GNUTLS_TLS1_2
       GNUTLS_TLS1_2,
