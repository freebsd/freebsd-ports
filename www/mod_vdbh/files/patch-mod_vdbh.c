--- mod_vdbh.c.orig	Sun Oct 19 16:25:25 2003
+++ mod_vdbh.c	Sun Oct 19 16:25:35 2003
@@ -77,9 +77,7 @@
 
 #include "ap_config_auto.h"
 
-#ifdef HAVE_STDDEF_H
 #include <stddef.h>
-#endif
 
 #include <stdlib.h>
 #include <stdio.h>
