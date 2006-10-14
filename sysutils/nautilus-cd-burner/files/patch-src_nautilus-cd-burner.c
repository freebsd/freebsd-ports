--- src/nautilus-cd-burner.c.orig	Tue May  9 13:31:13 2006
+++ src/nautilus-cd-burner.c	Mon May 15 21:11:00 2006
@@ -27,6 +27,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
