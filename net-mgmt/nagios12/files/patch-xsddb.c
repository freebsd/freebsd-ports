--- xdata/xsddb.c.orig	Thu Nov 14 03:51:34 2002
+++ xdata/xsddb.c	Thu Mar  6 23:16:27 2003
@@ -48,7 +48,7 @@
 #endif
 
 #ifdef USE_XSDPGSQL
-#include <pgsql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 
