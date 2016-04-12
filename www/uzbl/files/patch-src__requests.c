--- src/requests.c.orig	2016-03-25 08:47:49 UTC
+++ src/requests.c
@@ -8,6 +8,7 @@
 
 #include <errno.h>
 #include <string.h>
+#include <stdarg.h>
 
 struct _UzblRequests {
     /* Reply buffer */
