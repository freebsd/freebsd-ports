
$FreeBSD$

--- ssh_logging.c	2001/04/18 15:57:35	1.1
+++ ssh_logging.c	2001/04/18 15:57:48
@@ -46,6 +46,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <time.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
 
