--- src/libqalculate/Calculator.cc.orig	Fri Mar 11 14:36:10 2005
+++ src/libqalculate/Calculator.cc	Fri Mar 11 14:36:17 2005
@@ -33,7 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <queue>
 #include <glib.h>
 
