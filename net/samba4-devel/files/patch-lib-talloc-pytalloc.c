--- ./lib/talloc/pytalloc.c.orig	2010-01-11 07:35:28.000000000 +0200
+++ ./lib/talloc/pytalloc.c	2012-01-12 19:48:39.276126537 +0200
@@ -19,7 +19,7 @@
 
 #include "replace.h"
 #include <talloc.h>
-#include <pytalloc.h>
+#include "pytalloc.h"
 
 /**
  * Simple dealloc for talloc-wrapping PyObjects
