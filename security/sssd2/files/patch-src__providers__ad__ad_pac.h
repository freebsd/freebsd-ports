--- src/providers/ad/ad_pac.h.orig	2023-06-05 04:04:46 UTC
+++ src/providers/ad/ad_pac.h
@@ -32,6 +32,8 @@
 #ifdef ldb_val
 #error Please make sure to include ad_pac.h before ldb.h
 #endif
+#include <unistd.h>
+#include <time.h>
 #include <ndr.h>
 #include <gen_ndr/krb5pac.h>
 #include <gen_ndr/ndr_krb5pac.h>
