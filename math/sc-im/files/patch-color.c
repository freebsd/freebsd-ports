--- color.c.orig	2019-02-22 18:41:46 UTC
+++ color.c
@@ -60,6 +60,8 @@
 #include "conf.h"
 #include "cmds.h"
 
+struct ucolor ucolors[N_INIT_PAIRS] = {};
+
 static struct dictionary * d_colors_param = NULL;
 
 struct dictionary * get_d_colors_param() {
