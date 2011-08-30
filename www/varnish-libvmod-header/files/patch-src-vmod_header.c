--- src/vmod_header.c.orig	2011-08-31 00:58:34.000000000 +0200
+++ src/vmod_header.c	2011-08-31 00:59:08.000000000 +0200
@@ -30,8 +30,8 @@
 #include <pthread.h>
 
 #include "vrt.h"
-#include "bin/varnishd/cache.h"
-#include "include/vct.h"
+#include "varnish/cache.h"
+#include "vct.h"
 
 #include "vcc_if.h"
 #include "config.h"
