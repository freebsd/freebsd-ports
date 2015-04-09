--- xclip.c.orig	2015-04-08 18:22:12 UTC
+++ xclip.c
@@ -10,6 +10,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 
 #include "mt.h"
 #include "error.h"
