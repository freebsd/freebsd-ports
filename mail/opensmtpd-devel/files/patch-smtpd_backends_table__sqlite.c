
$FreeBSD$

--- smtpd/backends/table_sqlite.c.orig
+++ smtpd/backends/table_sqlite.c
@@ -22,6 +22,7 @@
 
 #include <ctype.h>
 #include <fcntl.h>
+#include <getopt.h>
 #include <sqlite3.h>
 #include <stdio.h>
 #include <stdlib.h>
