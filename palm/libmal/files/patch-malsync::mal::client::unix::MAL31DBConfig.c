--- malsync/mal/client/unix/MAL31DBConfig.c.orig	Sun Nov 10 12:44:33 2002
+++ malsync/mal/client/unix/MAL31DBConfig.c	Sun Nov 10 12:45:52 2002
@@ -20,11 +20,7 @@
  */
 
 #include <MAL31DBConfig.h>
-#ifdef DARWIN
 #include <stdlib.h>
-#else
-#include <malloc.h>
-#endif
 
 /*---------------------------------------------------------------------------*/
 void
