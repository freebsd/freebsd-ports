
$FreeBSD$

--- channels/chan_iax2.c
+++ channels/chan_iax2.c
@@ -52,7 +52,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 #endif
 
