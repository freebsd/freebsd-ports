--- cfg.c.orig	Fri Jul 12 11:30:59 2002
+++ cfg.c	Fri Jul 12 11:31:08 2002
@@ -35,6 +35,8 @@
  * This code was written under funding by Ericsson Radio Systems.
  */
 
+#include "cfg.h"
+
 #ifndef WIN32
 #include <sys/param.h>
 #include <sys/mman.h>
@@ -51,7 +53,6 @@
 #include <err.h>
 
 #include "config.h"
-#include "cfg.h"
 
 struct conf_trans {
 	TAILQ_ENTRY (conf_trans) link;
