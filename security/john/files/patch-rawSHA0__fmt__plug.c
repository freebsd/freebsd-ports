--- rawSHA0_fmt_plug.c.orig	2014-09-19 16:40:51 UTC
+++ rawSHA0_fmt_plug.c
@@ -6,6 +6,10 @@
  * Based on Raw-SHA1, but this is OpenSSL only.
  */
 
+#include <openssl/sha.h>
+
+#ifndef OPENSSL_NO_SHA0
+
 #if FMT_EXTERNS_H
 extern struct fmt_main fmt_rawSHA_0;
 #elif FMT_REGISTERS_H
@@ -13,7 +17,6 @@ john_register_one(&fmt_rawSHA_0);
 #else
 
 #include <string.h>
-#include <openssl/sha.h>
 
 #include "arch.h"
 #include "misc.h"
@@ -208,3 +211,5 @@ struct fmt_main fmt_rawSHA_0 = {
 };
 
 #endif /* plugin stanza */
+
+#endif /* OPENSSL_NO_SHA0 */
