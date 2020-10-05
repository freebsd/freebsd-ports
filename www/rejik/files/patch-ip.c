--- ip.c.orig	2013-11-15 10:28:02 UTC
+++ ip.c
@@ -3,6 +3,8 @@
 #include <string.h>
 #include "vars.h"
 
+char *input_ip;
+
 int add_ip(char *string,char **ip_list,int *count)
 {
  char *k,*k1,tmp[ML_CFG],etmp[ML_ETMP];
