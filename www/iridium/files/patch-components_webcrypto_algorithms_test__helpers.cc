--- components/webcrypto/algorithms/test_helpers.cc.orig	2018-06-13 00:10:16.000000000 +0200
+++ components/webcrypto/algorithms/test_helpers.cc	2018-07-19 00:07:52.270703000 +0200
@@ -25,7 +25,11 @@
 #include "components/webcrypto/status.h"
 #include "third_party/blink/public/platform/web_crypto_algorithm_params.h"
 #include "third_party/blink/public/platform/web_crypto_key_algorithm.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace webcrypto {
 
