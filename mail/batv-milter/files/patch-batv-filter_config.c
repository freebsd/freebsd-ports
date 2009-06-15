--- ./batv-filter/config.c.orig	2009-04-22 02:43:48.000000000 +0900
+++ ./batv-filter/config.c	2009-06-04 07:30:43.000000000 +0900
@@ -17,7 +17,12 @@
 #include <assert.h>
 
 /* libsm includes */
-#include <sm/string.h>
+#ifdef WITHOUT_SMSTRING
+# define sm_strlcat     strlcat
+# define sm_strlcpy     strlcpy
+#else /* WITHOUT_SMSTRING */
+# include <sm/string.h>
+#endif /* WITHOUT_SMSTRING */
 
 /* dkim-filter includes */
 #include "config.h"
