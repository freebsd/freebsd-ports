--- dns.c.orig
+++ dns.c
@@ -7,7 +7,6 @@
 #include <errno.h>
 extern int res_query();
 extern int res_search();
-extern int errno;
 extern int h_errno;
 #include "ip.h"
 #include "ipalloc.h"
