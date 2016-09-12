--- src/rawSHA0_fmt.c.orig	2012-09-17 08:30:39 UTC
+++ src/rawSHA0_fmt.c
@@ -9,6 +9,8 @@
 #include <string.h>
 #include "sha.h"
 
+#ifndef OPENSSL_NO_SHA0
+
 #include "arch.h"
 #include "misc.h"
 #include "common.h"
@@ -189,3 +191,5 @@ struct fmt_main fmt_rawSHA0 = {
 		cmp_exact
 	}
 };
+
+#endif
