--- foremost.h.orig	Fri Jan  9 13:45:23 2004
+++ foremost.h	Wed Jun 16 22:51:42 2004
@@ -40,6 +40,7 @@
 #define  strtoull   strtoul
 #include <sys/ttycom.h>
 #include <sys/param.h>
+#include <libgen.h>	/* for basename() */
 #endif  /* ifdef __OPENBSD */
 
 #ifdef __LINUX
@@ -178,7 +179,7 @@
 #define FOREMOST_NOEXTENSION '\xFF'
 
 #define FOREMOST_DEFAULT_WILDCARD       '?'
-#define FOREMOST_DEFAULT_CONFIG_FILE    "foremost.conf"
+#define FOREMOST_DEFAULT_CONFIG_FILE    "PREFIX/etc/foremost.conf"
 
 #define FOREMOST_DEFAULT_OUTPUT_DIR     "foremost-output"
