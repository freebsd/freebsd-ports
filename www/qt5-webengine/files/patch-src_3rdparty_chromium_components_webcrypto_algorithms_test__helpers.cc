--- src/3rdparty/chromium/components/webcrypto/algorithms/test_helpers.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/webcrypto/algorithms/test_helpers.cc
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
 
