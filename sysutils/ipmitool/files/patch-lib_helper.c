--- lib/helper.c.orig	2022-09-01 18:42:31 UTC
+++ lib/helper.c
@@ -54,7 +54,7 @@
 #ifdef HAVE_PATHS_H
 # include <paths.h>
 #else
-# define _PATH_RUN "/run/"
+# define _PATH_RUN "/var/run/"
 #endif
 
 #include <ipmitool/ipmi.h>
