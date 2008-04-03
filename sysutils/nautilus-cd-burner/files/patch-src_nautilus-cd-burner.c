--- src/nautilus-cd-burner.c.orig	2008-01-21 11:16:24.000000000 -0500
+++ src/nautilus-cd-burner.c	2008-04-02 16:48:23.000000000 -0400
@@ -27,6 +27,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
