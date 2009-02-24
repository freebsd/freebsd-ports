--- tools/mopen/mopen1.cpp.orig	2009-02-13 14:08:20.000000000 +0000
+++ tools/mopen/mopen1.cpp	2009-02-13 14:08:37.000000000 +0000
@@ -14,6 +14,7 @@
 //    Implement everything mopen implements
 //
 
+#include <sys/stat.h>
 #include <config.h>
 #include <gtk/gtk.h>
 #include <unistd.h>
