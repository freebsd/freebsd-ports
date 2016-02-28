--- cpp/util/bignum.h.orig	2016-02-02 11:35:23 UTC
+++ cpp/util/bignum.h
@@ -3,6 +3,7 @@
 
 #include <openssl/bn.h>
 #include <cassert>
+#include <stdint.h>
 
 namespace cert_trans {
 
