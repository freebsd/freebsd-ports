--- libmutt/rfc2047.c	Wed Jul 18 10:47:01 2001
+++ libmutt/rfc2047.c.new	Tue Sep 18 16:18:18 2001
@@ -24,7 +24,7 @@
 
 #include <ctype.h>
 #include <errno.h>
-#include <iconv.h>
+#include <giconv.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
