$FreeBSD$

--- src/parse.y.orig	Thu Jun 17 09:57:08 2004
+++ src/parse.y	Thu Jun 17 09:58:28 2004
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "powerman.h"
 #include "list.h"
@@ -48,6 +49,10 @@
 #include "device_tcp.h"
 #include "error.h"
 #include "string.h"
+
+#ifdef __FreeBSD__
+typedef int reg_syntax_t;
+#endif
 
 /*
  * A PreScript is a list of PreStmts.
