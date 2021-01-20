--- src/suricata-common.h.orig	2020-12-04 07:11:05 UTC
+++ src/suricata-common.h
@@ -36,6 +36,8 @@
 #define _GNU_SOURCE
 #define __USE_GNU
 
+#include "queue.h"
+
 #if HAVE_CONFIG_H
 #include <config.h>
 #endif
