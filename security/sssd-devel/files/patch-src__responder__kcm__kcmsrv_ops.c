--- src/responder/kcm/kcmsrv_ops.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/kcm/kcmsrv_ops.c
@@ -21,6 +21,7 @@
 
 #include "config.h"
 
+#include <sys/endian.h>
 #include <krb5/krb5.h>
 #include <dhash.h>
 
