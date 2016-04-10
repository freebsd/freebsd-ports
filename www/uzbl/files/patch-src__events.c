--- src/events.c.orig	2016-02-28 14:27:33 UTC
+++ src/events.c
@@ -5,6 +5,7 @@
 #include "util.h"
 #include "uzbl-core.h"
 
+#include <stdarg.h>
 #include <string.h>
 
 const char *event_table[] = {
