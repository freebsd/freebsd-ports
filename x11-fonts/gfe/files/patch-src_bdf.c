
$FreeBSD$

--- src/bdf.c.orig	Tue Jun 27 12:36:09 2000
+++ src/bdf.c	Sat Nov 30 02:04:14 2002
@@ -18,7 +18,8 @@
 #include <gtk/gtk.h>
 
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "auxil.h"
 #include "bdf.h"
