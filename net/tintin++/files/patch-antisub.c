--- antisub.c.orig	Sun Nov 17 13:26:33 2002
+++ antisub.c	Sun Nov 17 13:26:43 2002
@@ -6,12 +6,8 @@
 /*                     coded by peter unold 1992                     */
 /*********************************************************************/
 #include "tintin.h"
-#ifdef HAVE_STRING_H
-#include <string.h>
-#else
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
-#endif
 #endif
 
 #ifdef HAVE_STDLIB_H
