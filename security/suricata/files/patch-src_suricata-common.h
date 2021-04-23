--- src/suricata-common.h.orig	2021-03-01 16:13:22 UTC
+++ src/suricata-common.h
@@ -36,6 +36,8 @@
 #define _GNU_SOURCE
 #define __USE_GNU
 
+#include "queue.h"
+
 #if HAVE_CONFIG_H
 #include <autoconf.h>
 #endif
