--- src/util/sss_pam_data.h.orig	2023-05-05 08:11:07 UTC
+++ src/util/sss_pam_data.h
@@ -24,6 +24,7 @@
 #include "config.h"
 #include <stdbool.h>
 #include <stdint.h>
+#include <string.h>
 #ifdef USE_KEYRING
 #include <sys/types.h>
 #include <keyutils.h>
