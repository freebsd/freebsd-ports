--- id.c.orig	2013-11-15 10:28:02 UTC
+++ id.c
@@ -5,6 +5,8 @@
 #include <string.h>
 #include "vars.h"
 
+char *input_ident_un;
+
 int add_id(char *string,char ***id_list,int *count)
 {
  char tmp[ML_CFG],etmp[ML_ETMP], *k;
