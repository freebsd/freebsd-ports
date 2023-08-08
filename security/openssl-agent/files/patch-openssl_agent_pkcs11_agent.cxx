--- openssl/agent/pkcs11/agent.cxx.orig	2023-02-09 15:36:17 UTC
+++ openssl/agent/pkcs11/agent.cxx
@@ -24,6 +24,9 @@
 #include <openssl/agent/pkcs11/options.hxx>
 #include <openssl/agent/pkcs11/private-key.hxx>
 
+#include <sys/signal.h>
+#define _NSIG NSIG
+
 namespace openssl
 {
   namespace agent
