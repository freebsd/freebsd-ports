--- src/rmd_rescue.c.orig	2009-03-09 15:07:06.000000000 +0800
+++ src/rmd_rescue.c	2009-03-09 15:07:28.000000000 +0800
@@ -37,6 +37,7 @@
 #include <pthread.h>
 
 #include <string.h>
+#include <stdlib.h>
 
 
 int rmdRescue(const char *path){
