--- src/rmd_cache.c.orig	2009-03-09 14:57:05.000000000 +0800
+++ src/rmd_cache.c	2009-03-09 14:57:46.000000000 +0800
@@ -30,6 +30,8 @@
 #include "rmd_specsfile.h"
 #include "rmd_types.h"
 
+#include <sys/types.h>
+#include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
