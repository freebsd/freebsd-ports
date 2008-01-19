diff -ruN sphinx-0.9.8-svn-r1065.orig/src/searchd.cpp sphinx-0.9.8-svn-r1065/src/searchd.cpp
--- src/searchd.cpp	2008-01-14 01:49:00.000000000 +0100
+++ src/searchd.cpp	2008-01-18 23:44:55.000000000 +0100
@@ -20,6 +20,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <time.h>
