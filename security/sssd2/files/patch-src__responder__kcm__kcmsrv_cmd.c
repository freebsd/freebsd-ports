--- src/responder/kcm/kcmsrv_cmd.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/kcm/kcmsrv_cmd.c
@@ -20,10 +20,12 @@
 */
 
 #include <sys/uio.h>
+#include <sys/endian.h>
 #include <krb5/krb5.h>
 
 #include "config.h"
 #include "util/util.h"
+#include "util/sss_bsd_errno.h"
 #include "responder/common/responder.h"
 #include "responder/kcm/kcmsrv_pvt.h"
 #include "responder/kcm/kcmsrv_ops.h"
