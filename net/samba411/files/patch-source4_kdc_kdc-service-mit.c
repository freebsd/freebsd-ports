--- source4/kdc/kdc-service-mit.c.orig	2019-01-15 10:07:00 UTC
+++ source4/kdc/kdc-service-mit.c
@@ -36,9 +36,13 @@
 #include "kdc/samba_kdc.h"
 #include "kdc/kdc-server.h"
 #include "kdc/kpasswd-service.h"
-#include <kadm5/admin.h>
 #include <kdb.h>
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wstrict-prototypes"
+#include <kadm5/admin.h>
+#pragma clang diagnostic pop
+
 #include "source4/kdc/mit_kdc_irpc.h"
 
 /* PROTOTYPES */
