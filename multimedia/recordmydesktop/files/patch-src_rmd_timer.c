--- src/rmd_timer.c.orig	2009-03-09 15:07:55.000000000 +0800
+++ src/rmd_timer.c	2009-03-09 15:08:25.000000000 +0800
@@ -34,6 +34,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 
 
 void *rmdTimer(ProgData *pdata){
