--- getline_ssl.c.orig	Mon May  1 00:18:22 2006
+++ getline_ssl.c	Mon May  1 00:18:25 2006
@@ -38,7 +38,6 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
 #include <stdarg.h>
 #include <fcntl.h>
 #include <sys/time.h>
@@ -50,6 +49,7 @@
 #include <netdb.h>
 #include <stdlib.h>
 #include <sys/wait.h>
+#include <stdlib.h>
 
 #include "getline_ssl.h"
 
