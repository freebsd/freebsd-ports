--- src/gq-server.c.orig	2008-04-30 04:15:42.000000000 +0000
+++ src/gq-server.c	2008-04-30 04:15:11.000000000 +0000
@@ -25,6 +25,7 @@
 
 #include "gq-server.h"
 
+#include <sys/select.h>
 #include <errno.h>
 #include <string.h>
 
