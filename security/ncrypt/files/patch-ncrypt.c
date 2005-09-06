--- ncrypt.c.orig	Tue Aug 30 10:57:04 2005
+++ ncrypt.c	Tue Aug 30 10:57:30 2005
@@ -17,6 +17,7 @@
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <unistd.h>
+#include <getopt.h>
 #include "ncrypt.h"
 #include "config.h"
 #include "encrypt_file.h"
