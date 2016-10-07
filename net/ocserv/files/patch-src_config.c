--- src/config.c.orig	2016-09-22 13:51:31 UTC
+++ src/config.c
@@ -54,8 +54,7 @@
 #include <occtl/ctl.h>
 #include "common-config.h"
 
-#define OLD_DEFAULT_CFG_FILE "/etc/ocserv.conf"
-#define DEFAULT_CFG_FILE "/etc/ocserv/ocserv.conf"
+#define DEFAULT_CFG_FILE "/usr/local/etc/ocserv/conf"
 
 static char pid_file[_POSIX_PATH_MAX] = "";
 static char cfg_file[_POSIX_PATH_MAX] = DEFAULT_CFG_FILE;
@@ -436,7 +435,7 @@ static void figure_auth_funcs(struct per
 			}
 			talloc_free(auth[j]);
 		}
-		fprintf(stderr, NOTESTR"setting '%s' as primary authentication method\n", config->auth[0].name);
+		/* fprintf(stderr, NOTESTR"Setting '%s' as primary authentication method\n", config->auth[0].name); */
 	} else {
 		unsigned x = config->auth_methods;
 		/* Append authentication methods (alternative options) */
@@ -663,11 +662,8 @@ size_t urlfw_size = 0;
 #endif
 
 	pov = configFileLoad(file);
-	if (pov == NULL && file != NULL && strcmp(file, DEFAULT_CFG_FILE) == 0)
-		pov = configFileLoad(OLD_DEFAULT_CFG_FILE);
-
 	if (pov == NULL) {
-		fprintf(stderr, ERRSTR"cannot load config file %s\n", file);
+		fprintf(stderr, ERRSTR"Cannot load config file %s\n", file);
 		exit(1);
 	}
 
