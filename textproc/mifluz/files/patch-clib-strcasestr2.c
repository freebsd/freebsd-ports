--- ./clib/strcasestr2.c.orig	2013-01-16 13:42:43.213865659 +0800
+++ ./clib/strcasestr2.c	2013-01-16 13:50:06.277425451 +0800
@@ -12,6 +12,7 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
+#ifndef HAVE_STRCASESTR
 #include <ctype.h>
 #include <string.h>
 
@@ -32,3 +33,4 @@
     }
     return 0;
 }
+#endif /* HAVE_STRCASESTR */
