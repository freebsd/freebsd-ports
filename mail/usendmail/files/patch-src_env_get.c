--- src/env_get.c.orig	2003-04-24 07:07:23 UTC
+++ src/env_get.c
@@ -4,7 +4,6 @@
  */
 #include "env.h"
 
-extern char **environ;
 char *env_get(const char *var)
 {
 	int e;
