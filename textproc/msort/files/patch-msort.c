--- msort.c.orig	Fri Jan 12 08:21:54 2007
+++ msort.c	Mon Jan 22 10:32:56 2007
@@ -49,6 +49,7 @@
 #include <time.h>
 #include <errno.h>
 #include <uninum/nsdefs.h>
+#include "unicode.h"
 #include <uninum/uninum.h>
 #include <tre/regex.h>
 
@@ -58,7 +59,6 @@
 typedef unsigned long ULongLong;
 #endif
 
-#include "unicode.h"
 #include "exitcode.h"
 #include "retcodes.h"
 #include "input.h"
