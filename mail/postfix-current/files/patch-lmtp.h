--- ./src/lmtp/lmtp.h.orig	Fri Jan 19 15:43:06 2001
+++ ./src/lmtp/lmtp.h	Sat Feb  3 14:01:09 2001
@@ -12,8 +12,8 @@
   * SASL library.
   */
 #ifdef USE_SASL_AUTH
-#include <sasl.h>
-#include <saslutil.h>
+#include <sasl/sasl.h>
+#include <sasl/saslutil.h>
 #endif
 
  /*
