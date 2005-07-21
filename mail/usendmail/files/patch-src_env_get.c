--- src/env_get.c.orig	Wed Jul 20 19:28:21 2005
+++ src/env_get.c	Wed Jul 20 19:28:43 2005
@@ -4,7 +4,6 @@
  */
 #include "env.h"
 
-extern char **environ;
 char *env_get(const char *var)
 {
 	int e;
