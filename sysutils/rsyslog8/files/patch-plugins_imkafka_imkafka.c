--- plugins/imkafka/imkafka.c.orig	2026-02-28 14:27:13 UTC
+++ plugins/imkafka/imkafka.c
@@ -27,6 +27,7 @@
     #define _GNU_SOURCE /* for timegm */
 #endif
 #define _XOPEN_SOURCE 700 /* for strptime */
+#define __BSD_VISIBLE 1	  /* for uint typedef */
 #include "config.h"
 #include <stdio.h>
 #include <stdarg.h>
