--- xdata/xrddb.c.orig	Thu May 16 04:46:11 2002
+++ xdata/xrddb.c	Thu Mar  6 23:16:14 2003
@@ -43,7 +43,7 @@
 #endif
 
 #ifdef USE_XRDPGSQL
-#include <pgsql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 
