--- readconfig.h.orig	2009-11-11 01:55:07 UTC
+++ readconfig.h
@@ -13,7 +13,7 @@
 #endif
 
 #if withPGSQL
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 #include <stdlib.h>
@@ -118,6 +118,6 @@ int config_read_config_file(t_config * config,char * f
 void config_destroy(t_config * config);
 char * get_dump_type_str(e_dumptypes dumptype);
 
-char conf_file[FILELENGTH];
+extern char conf_file[FILELENGTH];
 
 #endif
