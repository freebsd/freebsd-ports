--- apache2/mod_security.c.orig	Sun Jun 20 11:09:56 2004
+++ apache2/mod_security.c	Sun Jun 20 11:10:04 2004
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/stat.h>
 
 #ifdef WIN32
 #include <direct.h>
