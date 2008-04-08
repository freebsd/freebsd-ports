--- src/gvnc.c.orig	2008-04-06 18:35:22.000000000 -0400
+++ src/gvnc.c	2008-04-07 20:37:54.647022975 -0400
@@ -16,7 +16,7 @@
 
 #include <netdb.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <errno.h>
