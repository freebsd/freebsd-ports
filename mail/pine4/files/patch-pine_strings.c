--- pine/strings.c.Dist	Wed Nov 20 10:19:45 2002
+++ pine/strings.c	Tue Nov 26 03:23:21 2002
@@ -81,7 +81,7 @@
  ====*/
 
 #include "headers.h"
-#include "../c-client/utf8.h"
+#include "utf8.h"
 
 typedef struct role_args {
     char    *ourcharset;
