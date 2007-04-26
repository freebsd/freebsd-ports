
$FreeBSD$

--- res/res_musiconhold.c
+++ res/res_musiconhold.c
@@ -40,7 +40,7 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 #endif
 #include <unistd.h>
