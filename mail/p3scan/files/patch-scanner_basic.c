--- scanner_basic.c.orig	Tue Feb 17 21:58:49 2004
+++ scanner_basic.c	Tue Feb 17 22:20:28 2004
@@ -34,8 +34,9 @@
 #include <string.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
+#include <netinet/in.h>
 #include <errno.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <pcre.h>
 
 #include "p3scan.h"
