--- malsync/mal/client/unix/MAL31DBConfig.c.orig	Sat Nov 16 13:07:58 2002
+++ malsync/mal/client/unix/MAL31DBConfig.c	Sat Nov 16 13:08:26 2002
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
