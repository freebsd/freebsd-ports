--- framework/bioapi_util/memfuncs.c	Wed Jun  8 02:51:05 2005
+++ framework/bioapi_util/memfuncs.c	Sat Nov 19 15:28:53 2005
@@ -15,7 +15,7 @@
 
 /* Linux-Port: added <malloc.h> include file */
 #if defined (UNIX)
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #ifdef _DEBUG
