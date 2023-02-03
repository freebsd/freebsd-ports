Index: Source/WebCore/crypto/algorithms/CryptoAlgorithmAES_GCM.cpp
--- Source/WebCore/crypto/algorithms/CryptoAlgorithmAES_GCM.cpp.orig
+++ Source/WebCore/crypto/algorithms/CryptoAlgorithmAES_GCM.cpp
@@ -26,6 +26,12 @@
 #include "config.h"
 #include "CryptoAlgorithmAES_GCM.h"
 
+#if defined(_LP64)
+#  define __WORDSIZE 64
+#else
+#  define __WORDSIZE 32
+#endif
+
 #if ENABLE(WEB_CRYPTO)
 
 #include "CryptoAlgorithmAesGcmParams.h"
