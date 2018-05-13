--- gsd/gsd.c.orig	2018-05-13 20:11:47 UTC
+++ gsd/gsd.c
@@ -20,6 +20,7 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/stat.h>
 
 #include "gsd.h"
 
