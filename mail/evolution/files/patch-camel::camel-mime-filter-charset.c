
$FreeBSD$

--- camel/camel-mime-filter-charset.c	2001/03/16 19:41:33	1.1
+++ camel/camel-mime-filter-charset.c	2001/03/16 19:41:44
@@ -19,7 +19,7 @@
  */
 
 
-#include <iconv.h>
+#include <giconv.h>
 
 #include <string.h>
 #include <errno.h>
