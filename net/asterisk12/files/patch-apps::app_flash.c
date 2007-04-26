
$FreeBSD$

--- apps/app_flash.c
+++ apps/app_flash.c
@@ -31,7 +31,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 
 #include "asterisk.h"
