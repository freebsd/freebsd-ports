--- src/manage_sql_secinfo.c	2020-12-31 16:49:24.318202000 -0500
+++ src/manage_sql_secinfo.c	2020-12-31 16:49:46.253146000 -0500
@@ -44,6 +44,7 @@
 #include <sys/file.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 
 #include <gvm/base/proctitle.h>
