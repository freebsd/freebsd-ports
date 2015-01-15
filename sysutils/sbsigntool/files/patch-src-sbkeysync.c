--- src/sbkeysync.c.orig	2014-11-30 19:18:11.000000000 +0100
+++ src/sbkeysync.c	2014-11-30 19:18:32.000000000 +0100
@@ -38,7 +38,8 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/stat.h>
-#include <sys/statfs.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <sys/types.h>
 
 #include <getopt.h>
