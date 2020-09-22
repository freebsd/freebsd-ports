--- src/readconf.c.orig	2003-04-17 11:12:41 UTC
+++ src/readconf.c
@@ -19,6 +19,10 @@
  */
 
 #include "includes.h"
+
+CONFIG cf;
+STRUCTURE_REGEXS reg;
+
 void lt_set_config_err(char *option, char *val) {
 	printf("Error: invalid value [%s] to option [%s] in cfg file\n", val, option);
 	exit (1);
