--- checkq.c.orig	2011-12-15 12:22:43.000000000 +0100
+++ checkq.c	2011-12-15 12:23:47.000000000 +0100
@@ -21,6 +21,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <dirent.h>
+#include <string.h>
 
 int main(int argc, char *argv)
 {
