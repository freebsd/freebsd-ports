diff --git src/util/sss_krb5.c src/util/sss_krb5.c
index c0cc28a75..88e6e6008 100644
--- src/util/sss_krb5.c
+++ src/util/sss_krb5.c
@@ -28,6 +28,7 @@
 #include "util/sss_iobuf.h"
 #include "util/util.h"
 #include "util/sss_krb5.h"
+#include "util/sss_endian.h"
 
 static char *
 sss_krb5_get_primary(TALLOC_CTX *mem_ctx,
