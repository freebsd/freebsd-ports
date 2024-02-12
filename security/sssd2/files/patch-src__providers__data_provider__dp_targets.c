--- src/providers/data_provider/dp_targets.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/data_provider/dp_targets.c
@@ -26,6 +26,7 @@
 #include "providers/data_provider/dp_private.h"
 #include "providers/data_provider/dp_builtin.h"
 #include "providers/backend.h"
+#include "util/sss_bsd_errno.h"
 #include "util/util.h"
 
 #define DP_TARGET_INIT_FN "sssm_%s_%s_init"
