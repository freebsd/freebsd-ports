--- src/media/image.c.orig	2014-09-14 19:16:31 UTC
+++ src/media/image.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h> /* On many systems (Darwin...), stdio.h is a prerequisite. */
 #include <string.h>
+#include <sys/types.h>
 
 #include <netinet/in.h> /* ntohl */
 
