--- init_vars.c.orig	2013-11-15 10:28:02 UTC
+++ init_vars.c
@@ -1,6 +1,14 @@
 #include <stdlib.h>
 #include "vars.h"
 
+char *change_reason;
+struct p_url *i_url;
+char *input_url;
+char *input_url_un;
+char *input_ident;
+char *input_host;
+char *input_method;
+
 void init_vars(void)
 {
   write_hostname_to_log=0;
