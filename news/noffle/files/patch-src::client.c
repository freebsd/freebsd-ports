--- src/client.c.orig	Sun Oct 26 22:31:18 2003
+++ src/client.c	Sun Oct 26 22:31:34 2003
@@ -8,6 +8,7 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <arpa/inet.h>
 #include <ctype.h>
