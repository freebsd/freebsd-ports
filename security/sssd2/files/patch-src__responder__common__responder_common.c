--- src/responder/common/responder_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/common/responder_common.c
@@ -33,6 +33,7 @@
 #include <popt.h>
 #include <dbus/dbus.h>
 
+#include "util/sss_bsd_errno.h"
 #include "util/util.h"
 #include "util/strtonum.h"
 #include "db/sysdb.h"
