--- src/bdf.c.orig	2000-06-27 10:36:09 UTC
+++ src/bdf.c
@@ -18,7 +18,8 @@
 #include <gtk/gtk.h>
 
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "auxil.h"
 #include "bdf.h"
