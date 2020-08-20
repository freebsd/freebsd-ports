--- bin/par.c.orig	2020-08-20 10:37:18 UTC
+++ bin/par.c
@@ -108,7 +108,7 @@
 
 #include "version.h"
 
-extern char	**environ;
+extern char	**enviro;
 
 typedef struct {
 	int	n;				/* proc n of n_opt processes */
