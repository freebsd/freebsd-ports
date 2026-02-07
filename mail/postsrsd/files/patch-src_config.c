--- src/config.c.orig	2023-07-15 18:53:41 UTC
+++ src/config.c
@@ -21,6 +21,7 @@
 #include "util.h"
 
 #include <errno.h>
+#include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
