--- src/rstring.c.orig	Sat Aug  7 03:01:05 2004
+++ src/rstring.c	Sat Aug  7 03:02:12 2004
@@ -30,7 +30,6 @@
 #include <string.h>
 #include <stdarg.h>
 #include <sys/types.h>
-#include <regex.h>
 #include <errno.h>
 #include <ctype.h>
 
@@ -38,6 +37,7 @@
 #include "rarray.h"
 #include "rstring.h"
 #include "error.h"
+#include <regex.h>
 #include "memchunk.h"
 #include "str.h"
 
