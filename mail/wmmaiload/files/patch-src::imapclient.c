--- src/imapclient.c.orig	Sun Nov 28 06:16:30 2004
+++ src/imapclient.c	Sun Nov 28 06:16:01 2004
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/select.h>
+#include <sys/time.h>
 
 #include "imapclient.h"
 
