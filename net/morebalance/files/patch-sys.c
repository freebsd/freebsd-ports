--- sys.c.orig	Sat Oct 11 20:37:45 2003
+++ sys.c	Sat Oct 11 20:38:00 2003
@@ -2,6 +2,7 @@
 #include "sys.h"
 
 /* System includes */
+#include <sys/types.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <stdlib.h>
