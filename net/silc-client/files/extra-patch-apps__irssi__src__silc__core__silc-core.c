--- ./apps/irssi/src/silc/core/silc-core.c.orig	2010-08-16 09:37:58.000000000 -0400
+++ ./apps/irssi/src/silc/core/silc-core.c	2010-08-16 09:38:17.000000000 -0400
@@ -41,6 +41,7 @@
 #include "fe-common/core/fe-channels.h"
 #include "fe-common/core/keyboard.h"
 #include "fe-common/silc/module-formats.h"
+#include "glib/goption.h"
 
 #ifndef SILC_PLUGIN
 /* Command line option variables */
