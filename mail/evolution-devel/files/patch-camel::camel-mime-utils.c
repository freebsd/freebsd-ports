
$FreeBSD$

--- camel/camel-mime-utils.c	2001/03/16 19:44:50	1.1
+++ camel/camel-mime-utils.c	2001/03/16 19:45:05
@@ -33,7 +33,7 @@
 #include <unistd.h>
 
 #include <unicode.h>
-#include <iconv.h>
+#include <giconv.h>
 
 #include <glib.h>
 #include <time.h>
