--- tparser.c.orig	Wed Oct 19 16:43:38 2005
+++ tparser.c	Wed Oct 19 16:43:49 2005
@@ -1141,7 +1141,7 @@
 
 const char *smapi_cvs_date(){
 static
-#include "../smapi/cvsdate.h"
+#include <smapi/cvsdate.h>
 return cvs_date;
 }
 
