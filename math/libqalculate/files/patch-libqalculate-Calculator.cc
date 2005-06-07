--- libqalculate/Calculator.cc.orig	Fri Jun  3 12:25:49 2005
+++ libqalculate/Calculator.cc	Fri Jun  3 12:25:59 2005
@@ -33,7 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <queue>
 #include <glib.h>
 
