--- dclock.c.orig	2008-07-08 12:35:18.000000000 +0900
+++ dclock.c	2012-10-08 00:28:47.000000000 +0900
@@ -7,6 +7,7 @@
  * manager: *Dclock.seconds: on
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <locale.h>
 #include <X11/Intrinsic.h>
 #include "Dclock.h"
@@ -114,6 +115,7 @@
     { "quit",	quit },
 };
 
+int
 main(argc, argv)
 char *argv[];
 {
@@ -122,10 +124,11 @@
     char *name, *rindex();
     XWMHints     *wmhints;       /* for proper input focus */
 
-    if (name = rindex(argv[0], '/'))
+    if ((name = rindex(argv[0], '/'))) {
 	name++;
-    else
+    } else {
 	name = argv[0];
+    }
 
     setlocale(LC_TIME, "");
 
