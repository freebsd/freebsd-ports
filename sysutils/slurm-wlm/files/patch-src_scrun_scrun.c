--- src/scrun/scrun.c.orig	2023-03-28 20:15:54 UTC
+++ src/scrun/scrun.c
@@ -45,6 +45,9 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 
 #include "src/common/data.h"
 #include "src/common/log.h"
@@ -186,7 +189,11 @@ static void _parse_create(int argc, char **argv)
 	}
 
 	if (!state.bundle) {
+#ifdef __FreeBSD__
+		char *dir = getcwd(NULL, PATH_MAX);
+#else
 		char *dir = get_current_dir_name();
+#endif
 		state.bundle = xstrdup(dir);
 		free(dir);
 	}
