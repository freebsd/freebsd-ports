--- src/subrender.c.orig	Sun Dec 14 19:20:54 2003
+++ src/subrender.c	Wed Dec 17 00:37:46 2003
@@ -25,11 +25,12 @@
 
 #include "config.h"
 
-#include <malloc.h>
+/* #include <malloc.h> */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
+#include "compat.h"
 #include "subconfig.h"
 
 #include "subglobals.h"
