--- mod_defensible.c.orig	2012-04-03 14:50:25 UTC
+++ mod_defensible.c
@@ -19,7 +19,8 @@
  *
  */
 
-#include <config.h>
+/*#include <config.h>*/
+#define VERSION "%%PORTVERSION%%"
 
 #include "apr_strings.h"
 
