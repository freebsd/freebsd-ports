--- src/core/model/cairo-wideint.c.orig	2018-12-24 11:24:00 UTC
+++ src/core/model/cairo-wideint.c
@@ -32,6 +32,7 @@
  */
 
 #include "cairo-wideint-private.h"
+#include <climits>
 
 /**
  * \file
