--- src/output-plugins/spo_alert_unixsock.c.orig	2018-10-06 12:34:15 UTC
+++ src/output-plugins/spo_alert_unixsock.c
@@ -44,6 +44,7 @@
 #endif /* !WIN32 */
 #include <unistd.h>
 #include <errno.h>
+#include <stdlib.h>
 
 #include "decode.h"
 #include "plugbase.h"
