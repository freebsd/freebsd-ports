--- include/util.h.orig	2022-01-19 12:03:06.000000000 -0800
+++ include/util.h	2022-01-23 14:44:04.712694000 -0800
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <stdbool.h>
 #include <sys/types.h>
+#include "config.h"
 #include "url.h"
 
 #define HEXD2ASC(x) (((x) < 10) ? ((x) + '0') : ((x) - 10 + 'A'))
