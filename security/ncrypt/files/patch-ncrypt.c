--- ncrypt.c.orig	2015-05-11 20:36:52 UTC
+++ ncrypt.c
@@ -17,6 +17,7 @@
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <unistd.h>
+#include <getopt.h>
 #include "ncrypt.h"
 #include "config.h"
 #include "encrypt_file.h"
