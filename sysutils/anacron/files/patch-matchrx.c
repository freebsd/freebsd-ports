--- matchrx.c.orig	2000-06-20 23:12:18 UTC
+++ matchrx.c
@@ -23,6 +23,7 @@
 
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <stdarg.h>
 #include <stdlib.h>
