--- rawSHA0_fmt_plug.c.orig	2014-09-19 16:40:51 UTC
+++ rawSHA0_fmt_plug.c
@@ -15,6 +15,8 @@ john_register_one(&fmt_rawSHA_0);
 #include <string.h>
 #include <openssl/sha.h>
 
+#ifndef OPENSSL_NO_SHA0
+
 #include "arch.h"
 #include "misc.h"
 #include "common.h"
@@ -207,4 +209,6 @@ struct fmt_main fmt_rawSHA_0 = {
 	}
 };
 
+#endif /* OPENSSL_NO_SHA0 */
+
 #endif /* plugin stanza */
