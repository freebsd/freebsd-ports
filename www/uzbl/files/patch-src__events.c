--- src/events.c.orig	2011-03-15 12:19:22.000000000 +0000
+++ src/events.c	2011-03-15 12:19:36.000000000 +0000
@@ -3,6 +3,7 @@
  ** (c) 2009 by Robert Manea
 */
 
+#include <stdarg.h>
 #include "uzbl-core.h"
 #include "events.h"
 #include "util.h"
