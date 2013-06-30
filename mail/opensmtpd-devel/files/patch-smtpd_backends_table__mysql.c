
$FreeBSD$

--- smtpd/backends/table_mysql.c.orig
+++ smtpd/backends/table_mysql.c
@@ -22,6 +22,7 @@
 
 #include <ctype.h>
 #include <fcntl.h>
+#include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
