
$FreeBSD$

--- src/parse.y.orig	Fri Feb 20 00:01:26 2004
+++ src/parse.y	Sun Sep  5 22:24:43 2004
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "powerman.h"
 #include "list.h"
@@ -50,6 +51,10 @@
 #include "error.h"
 #include "string.h"
 
+#ifdef __FreeBSD__
+typedef int reg_syntax_t;
+#endif
+
 /*
  * A PreScript is a list of PreStmts.
  */
@@ -754,6 +759,7 @@
         case EPL_NONODES:
             _errormsg("more plugs than nodes");
         default:
+	break;
     }
 
     if (!conf_addnodes(nodestr))
