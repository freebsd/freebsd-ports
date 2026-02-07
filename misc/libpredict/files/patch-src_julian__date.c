--- src/julian_date.c.orig	2017-12-09 13:54:50 UTC
+++ src/julian_date.c
@@ -1,3 +1,4 @@
+#include <time.h>
 #define _POSIX_C_SOURCE 1
 #include <predict/predict.h>
 #include <stdio.h>
