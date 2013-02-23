--- cmdline/cmdline_testafp.c.orig	2008-03-04 20:16:50.000000000 +0000
+++ cmdline/cmdline_testafp.c	2012-10-14 13:11:33.000000000 +0000
@@ -3,8 +3,8 @@
 	
 */
 
-#include "afp.h"
-#include "midlevel.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/midlevel.h"
 
 #include "cmdline_main.h"
 
diff -Naur afpfs-ng-0.8.1.orig/cmdline/getstatus.c afpfs-ng-0.8.1/cmdline/getstatus.c
