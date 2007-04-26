
$FreeBSD$

--- apps/app_zapbarge.c
+++ apps/app_zapbarge.c
@@ -36,7 +36,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 
 #include "asterisk.h"
