--- src/providers/data_provider/dp_modules.c.orig	2023-05-25 06:34:10 UTC
+++ src/providers/data_provider/dp_modules.c
@@ -23,6 +23,7 @@
 #include "providers/data_provider/dp.h"
 #include "providers/data_provider/dp_private.h"
 #include "providers/backend.h"
+#include "util/sss_bsd_errno.h"
 #include "util/util.h"
 
 /* There can be at most the same number of different modules loaded at
