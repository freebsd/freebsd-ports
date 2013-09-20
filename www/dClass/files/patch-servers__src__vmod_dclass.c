--- ./servers/src/vmod_dclass.c.orig	2013-06-21 11:07:44.000000000 +0900
+++ ./servers/src/vmod_dclass.c	2013-09-14 20:11:39.000000000 +0900
@@ -19,8 +19,8 @@
 
 #include "dclass_client.h"
 
-#include "vrt.h"
-#include "bin/varnishd/cache.h"
+#include "varnish/vrt.h"
+#include "varnish/cache.h"
 #include "vcc_if.h"
 
 
