--- cmdline/cmdline_afp.c.orig	2008-02-19 01:54:19.000000000 +0000
+++ cmdline/cmdline_afp.c	2012-10-14 13:11:33.000000000 +0000
@@ -3,9 +3,9 @@
 	
 */
 
-#include "afp.h"
-#include "midlevel.h"
-#include "map_def.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/midlevel.h"
+#include "afpfs-ng/map_def.h"
 
 #include <string.h>
 #include <stdio.h>
diff -Naur afpfs-ng-0.8.1.orig/cmdline/cmdline_testafp.c afpfs-ng-0.8.1/cmdline/cmdline_testafp.c
