$FreeBSD$

--- src/powermand.c.orig	Mon Mar 29 14:23:55 2004
+++ src/powermand.c	Mon Mar 29 14:24:44 2004
@@ -35,6 +35,10 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <assert.h>
+#ifdef __linux__
+#include <list.h>
+#endif
+#include <limits.h>
 
 #include "powerman.h"
 #include "list.h"
