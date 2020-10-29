--- src/suricata-common.h-orig	2020-10-25 16:56:49.454317000 +0100
+++ src/suricata-common.h	2020-10-25 16:57:06.035153000 +0100
@@ -36,6 +36,8 @@
 #define _GNU_SOURCE
 #define __USE_GNU
 
+#include "queue.h"
+
 #if HAVE_CONFIG_H
 #include <config.h>
 #endif
