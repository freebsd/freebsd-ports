--- components/webcrypto/algorithms/test_helpers.cc.orig	2016-03-05 21:20:58.677542744 +0100
+++ components/webcrypto/algorithms/test_helpers.cc	2016-03-05 21:21:13.733542071 +0100
@@ -26,7 +26,11 @@
 #include "components/webcrypto/status.h"
 #include "third_party/WebKit/public/platform/WebCryptoAlgorithmParams.h"
 #include "third_party/WebKit/public/platform/WebCryptoKeyAlgorithm.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace webcrypto {
 
