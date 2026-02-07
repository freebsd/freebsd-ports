--- inews.c.orig	Wed Aug  4 03:21:19 2004
+++ inews.c	Wed Aug  4 03:28:27 2004
@@ -30,6 +30,8 @@
 #endif
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #ifdef STDC_HEADERS
 #include <string.h>
@@ -463,7 +465,7 @@
 
 static char *message_id(void)
 {
-	sprintf(buff,"<%lx.%x@%s>",time(0),getpid(),fqdn);
+	sprintf(buff,"<%lx.%x@%s>",(unsigned long)time(0),getpid(),fqdn);
 	return (buff);
 }
 
