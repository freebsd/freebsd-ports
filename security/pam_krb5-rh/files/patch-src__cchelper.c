--- ./src/cchelper.c.orig	2012-12-14 22:20:31.000000000 -0500
+++ ./src/cchelper.c	2012-12-14 22:20:36.000000000 -0500
@@ -44,6 +44,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/signal.h>
 
 #include KRB5_H
 
