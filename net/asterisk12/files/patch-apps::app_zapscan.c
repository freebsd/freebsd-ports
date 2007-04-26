
$FreeBSD$

--- apps/app_zapscan.c
+++ apps/app_zapscan.c
@@ -38,7 +38,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 
 #include "asterisk.h"
