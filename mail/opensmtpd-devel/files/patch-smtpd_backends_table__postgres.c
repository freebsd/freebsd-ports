
$FreeBSD$

--- smtpd/backends/table_postgres.c.orig
+++ smtpd/backends/table_postgres.c
@@ -22,12 +22,13 @@
 
 #include <ctype.h>
 #include <fcntl.h>
+#include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 
 #include "smtpd-defines.h"
 #include "smtpd-api.h"
