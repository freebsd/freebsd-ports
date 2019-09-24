--- rewrite.c.orig	2019-07-04 06:42:58 UTC
+++ rewrite.c
@@ -5,6 +5,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <regex.h>
+#include <arpa/inet.h>
 #include "debug.h"
 #include "gconfig.h"
 #include "hash.h"
