diff --git src/providers/ad/ad_pac.h src/providers/ad/ad_pac.h
index 34f1e92c7..00a53cccd 100644
--- src/providers/ad/ad_pac.h
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
