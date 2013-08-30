--- ./src/vmod_statsd.c.orig	2013-08-30 15:04:47.000000000 +0900
+++ ./src/vmod_statsd.c	2013-08-30 15:05:44.000000000 +0900
@@ -2,8 +2,8 @@
 #include <stdio.h>
 #include <string.h>
 
-#include "vrt.h"
-#include "bin/varnishd/cache.h"
+#include "varnish/vrt.h"
+#include "varnish/cache.h"
 
 #include "vcc_if.h"
 
