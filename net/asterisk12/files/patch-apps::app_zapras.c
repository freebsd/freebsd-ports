
$FreeBSD$

--- apps/app_zapras.c
+++ apps/app_zapras.c
@@ -43,7 +43,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 
 #include "asterisk.h"
