--- xtar.c.orig	1995-07-17 19:44:19.000000000 +0800
+++ xtar.c	2013-08-15 17:00:58.000000000 +0800
@@ -33,6 +33,7 @@
 #include <sys/stat.h>
 #include <string.h>
 #include <unistd.h>
+#include <stdlib.h>
 
 #include <Xm/Xm.h>
 #include <Xm/Form.h>
@@ -408,7 +409,7 @@
     int argc = 1;
     char **argv;
 #else
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     char *mappings;
 #endif
@@ -1164,7 +1165,7 @@
 static int xtar_attributes(TAR_FILE *tf, char *filename)
 {
     int retval = 0;
-    struct utimbuf utimbuf;
+    struct utimbuf {char utimbuf;} utimbuf;
 
     /* If the file type is not a directory then try and set the access
        permissions. We exclude directories because if write permission
