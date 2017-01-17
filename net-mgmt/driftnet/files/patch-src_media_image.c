--- src/media/image.c.orig	2013-05-12 15:16:43 UTC
+++ src/media/image.c
@@ -10,6 +10,7 @@
 #include <stdio.h>
 #include <stdlib.h> /* On many systems (Darwin...), stdio.h is a prerequisite. */
 #include <string.h>
+#include <sys/types.h>
 
 #include <netinet/in.h> /* ntohl */
 
