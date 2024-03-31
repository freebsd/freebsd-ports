--- plugins/imdtls/imdtls.c.orig	2024-03-31 11:10:07 UTC
+++ plugins/imdtls/imdtls.c
@@ -23,6 +23,7 @@
  */
 #include "config.h"
 
+#include <signal.h>
 #include <stdio.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
