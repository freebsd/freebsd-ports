--- src/util/sss_krb5.c.orig	2020-03-17 13:31:28 UTC
+++ src/util/sss_krb5.c
@@ -28,6 +28,7 @@
 #include "util/sss_iobuf.h"
 #include "util/util.h"
 #include "util/sss_krb5.h"
+#include "util/sss_endian.h"
 
 static char *
 sss_krb5_get_primary(TALLOC_CTX *mem_ctx,
