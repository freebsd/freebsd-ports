--- postfix-1.1.13/src/lmtp/lmtp.h.orig	Fri Jan 19 15:43:06 2001
+++ postfix-1.1.13/src/lmtp/lmtp.h	Sat Feb  3 14:01:09 2001
@@ -12,8 +12,8 @@
   * SASL library.
   */
 #ifdef USE_SASL_AUTH
-#include <sasl.h>
-#include <saslutil.h>
+#include <sasl1/sasl.h>
+#include <sasl1/saslutil.h>
 #endif
 
  /*
