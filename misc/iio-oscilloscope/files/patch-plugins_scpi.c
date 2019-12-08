--- plugins/scpi.c.orig	2019-12-08 08:36:48 UTC
+++ plugins/scpi.c
@@ -40,7 +40,7 @@
 #include <stdbool.h>
 #include <stdint.h>
 #include <string.h>
-#include <sys/dir.h>
+#include <sys/dirent.h>
 #include <syslog.h>
 #include <sys/select.h>
 #include <sys/socket.h>
