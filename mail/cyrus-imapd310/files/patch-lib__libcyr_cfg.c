Index: lib/libcyr_cfg.c
diff -u -p lib/libcyr_cfg.c.orig lib/libcyr_cfg.c
--- lib/libcyr_cfg.c.orig	Wed Mar 10 00:05:58 2004
+++ lib/libcyr_cfg.c	Fri Feb 25 00:06:44 2005
@@ -52,7 +52,7 @@
 #include "libcyr_cfg.h"
 #include "cyrusdb.h"
 
-#if defined(__GNUC__) && __GNUC__ > 1
+#if defined(__GNUC__) && __GNUC__ > 1 && !defined(__INTEL_COMPILER)
 /* We can use the GCC union constructor extension */
 #define CFGVAL(t,v)	(union cyrus_config_value)((t)(v))
 #else
