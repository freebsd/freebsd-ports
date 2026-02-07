--- ./batv-filter/util.c.orig	2009-05-28 01:16:45.000000000 +0900
+++ ./batv-filter/util.c	2009-06-04 07:31:03.000000000 +0900
@@ -25,7 +25,13 @@
 #include <ctype.h>
 
 /* libsm includes */
-#include <sm/string.h>
+#ifdef WITHOUT_SMSTRING
+# define sm_strlcat     strlcat
+# define sm_strlcpy     strlcpy
+# include <sm/gen.h>
+#else /* WITHOUT_SMSTRING */
+# include <sm/string.h>
+#endif /* WITHOUT_SMSTRING */
 
 /* batv-filter includes */
 #include "batv-filter.h"
