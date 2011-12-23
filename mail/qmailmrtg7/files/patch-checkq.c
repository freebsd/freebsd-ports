--- checkq.c.orig	2004-02-29 10:54:02.000000000 +0100
+++ checkq.c	2011-12-23 10:20:40.000000000 +0100
@@ -21,8 +21,9 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <dirent.h>
+#include <string.h>
 
-int main(int argc, char *argv)
+int main(int argc, char **argv)
 {
  FILE *fs;
  DIR *mydir;
