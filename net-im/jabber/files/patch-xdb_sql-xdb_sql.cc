--- xdb_sql/xdb_sql.cc.orig	Sat Feb 17 10:57:25 2007
+++ xdb_sql/xdb_sql.cc	Sat Feb 17 10:57:36 2007
@@ -53,7 +53,7 @@
 #endif
 
 #ifdef HAVE_POSTGRESQL
-#  include <postgresql/libpq-fe.h>
+#  include <libpq-fe.h>
 #endif
 
 /**
