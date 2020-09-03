--- mace2/anldp.c.orig	2003-08-06 18:43:36 UTC
+++ mace2/anldp.c
@@ -41,6 +41,10 @@
 
 /************* END OF ALL GLOBAL CONSTANT DEFINITIONS ****************/
 
+#define IN_MAIN
+
+#include "../source/header.h"
+
 #include "Opts.h"
 #include "Stats.h"
 #include "Avail.h"
