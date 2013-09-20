--- vcc_if.c.orig	2013-09-14 19:38:57.000000000 +0900
+++ vcc_if.c	2013-09-14 19:39:41.000000000 +0900
@@ -4,9 +4,9 @@
  * Edit vmod.vcc and run vmod.py instead
  */
 
-#include "vrt.h"
+#include "varnish/vrt.h"
 #include "vcc_if.h"
-#include "vmod_abi.h"
+#include "varnish/vmod_abi.h"
 
 
 typedef void td_dclass_init_dclass(struct sess *, struct vmod_priv *, const char *);
