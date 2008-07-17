--- clib/strcasestr2.c.orig	2008-06-05 00:01:39.000000000 +0900
+++ clib/strcasestr2.c	2008-07-11 22:26:07.000000000 +0900
@@ -12,6 +12,8 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
+#ifndef HAVE_STRCASESTR
+
 #include <ctype.h>
 #include <string.h>
 
@@ -32,3 +34,4 @@
     }
     return 0;
 }
+#endif /* HAVE_STRCASESTR */
