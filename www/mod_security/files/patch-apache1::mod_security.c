--- apache1/mod_security.c.orig	Sun Jun 20 11:09:40 2004
+++ apache1/mod_security.c	Sun Jun 20 11:03:01 2004
@@ -23,6 +23,7 @@
 #include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/stat.h>
 
 #if !(defined(WIN32) || defined(NETWARE))
 #include <unistd.h>
