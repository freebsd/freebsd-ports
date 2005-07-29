--- scanner_basic.c.orig	Thu Jan  6 04:53:04 2005
+++ scanner_basic.c	Fri Jul 29 10:26:09 2005
@@ -33,9 +33,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/wait.h>
+#include <netinet/in.h>
 #include <sys/stat.h>
 #include <errno.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <pcre.h>
 
 #include "p3scan.h"
