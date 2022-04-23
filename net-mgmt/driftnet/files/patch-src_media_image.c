--- src/media/image.c.orig	2022-04-16 21:14:04 UTC
+++ src/media/image.c
@@ -12,6 +12,7 @@
 #include <stdio.h>
 #include <stdlib.h> /* On many systems (Darwin...), stdio.h is a prerequisite. */
 #include <string.h>
+#include <sys/types.h>
 
 #include <netinet/in.h> /* ntohl */
 
