
$FreeBSD$

--- smtpd/table_postgres.c.orig
+++ smtpd/table_postgres.c
@@ -28,7 +28,7 @@
 #include <time.h>
 #include <unistd.h>
 
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 
 #include "smtpd-defines.h"
 #include "smtpd-api.h"
