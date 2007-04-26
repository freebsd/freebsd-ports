
$FreeBSD$

--- apps/app_meetme.c
+++ apps/app_meetme.c
@@ -32,7 +32,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 
 #include "asterisk.h"
