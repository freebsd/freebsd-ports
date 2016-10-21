--- cpp/util/bignum.h.orig	2016-10-14 17:11:57 UTC
+++ cpp/util/bignum.h
@@ -3,6 +3,7 @@
 
 #include <openssl/bn.h>
 #include <cassert>
+#include <stdint.h>
 
 namespace cert_trans {
 
