--- src/rmd_get_frame.c.orig	2009-03-09 15:03:27.000000000 +0800
+++ src/rmd_get_frame.c	2009-03-09 15:03:45.000000000 +0800
@@ -43,6 +43,7 @@
 #include <pthread.h>
 #include <sys/shm.h>
 #include <errno.h>
+#include <stdlib.h>
 
 
 #define AVG_4_PIXELS(data_array,width_img,k_tm,i_tm,offset)\
