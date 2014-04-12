--- help.c.orig
+++ help.c
@@ -16,10 +16,11 @@
 #include "globals.h"
 
 extern char compile_time[], version[];
+extern void cmd_help();
 
 /*---------------------------------------------------------------------------*/
 
-cmd_help(orig_arg)
+void cmd_help(orig_arg)
 char *orig_arg;
 {
     char *arg, *lc = NULL, *try2 = NULL, *try3 = NULL, *try4 = NULL;
