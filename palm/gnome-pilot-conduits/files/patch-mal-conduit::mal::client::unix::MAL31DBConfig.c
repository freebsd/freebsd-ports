
$FreeBSD$

--- mal-conduit/mal/client/unix/MAL31DBConfig.c	2001/12/14 11:48:37	1.1
+++ mal-conduit/mal/client/unix/MAL31DBConfig.c	2001/12/14 11:49:50
@@ -20,7 +20,11 @@
  */
 
 #include <MAL31DBConfig.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 /*---------------------------------------------------------------------------*/
 void
