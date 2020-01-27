--- src/gq-server.c.orig	2008-01-09 16:35:12 UTC
+++ src/gq-server.c
@@ -25,6 +25,7 @@
 
 #include "gq-server.h"
 
+#include <sys/select.h>
 #include <errno.h>
 #include <string.h>
 
