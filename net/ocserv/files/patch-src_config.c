--- src/config.c.orig	2015-09-04 19:27:22 UTC
+++ src/config.c
@@ -51,8 +51,7 @@
 #include <tlslib.h>
 #include "common-config.h"
 
-#define OLD_DEFAULT_CFG_FILE "/etc/ocserv.conf"
-#define DEFAULT_CFG_FILE "/etc/ocserv/ocserv.conf"
+#define DEFAULT_CFG_FILE "/usr/local/etc/ocserv/conf"
 
 static char pid_file[_POSIX_PATH_MAX] = "";
 static char cfg_file[_POSIX_PATH_MAX] = DEFAULT_CFG_FILE;
@@ -416,7 +415,7 @@ static void figure_auth_funcs(struct per
 			}
 			talloc_free(auth[j]);
 		}
-		fprintf(stderr, "Setting '%s' as primary authentication method\n", config->auth[0].name);
+		/* fprintf(stderr, "Setting '%s' as primary authentication method\n", config->auth[0].name); */
 	} else {
 		unsigned x = config->auth_methods;
 		/* Append authentication methods (alternative options) */
@@ -586,9 +585,6 @@ size_t urlfw_size = 0;
 #endif
 
 	pov = configFileLoad(file);
-	if (pov == NULL && file != NULL && strcmp(file, DEFAULT_CFG_FILE) == 0)
-		pov = configFileLoad(OLD_DEFAULT_CFG_FILE);
-
 	if (pov == NULL) {
 		fprintf(stderr, "Error loading config file %s\n", file);
 		exit(1);
