--- lib/racoon.h~	2007-12-12 16:12:22.000000000 +0900
+++ lib/racoon.h	2008-08-13 13:20:32.000000000 +0900
@@ -42,7 +42,7 @@
 #include "script.h"
 #include "missing/missing.h"
 
-#define RACOON_CONF	SYSCONFDIR "/racoon2/racoon2.conf"
+#define RACOON_CONF	SYSCONFDIR "/racoon2.conf"
 
 extern int rct2isakmp_exmode __P((int));
 extern int rct2app_action __P((int));
