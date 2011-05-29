--- readconfig.h.orig	2009-11-10 20:55:07.000000000 -0500
+++ readconfig.h	2011-05-26 21:06:12.000000000 -0400
@@ -13,7 +13,7 @@
 #endif
 
 #if withPGSQL
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 #include <stdlib.h>
