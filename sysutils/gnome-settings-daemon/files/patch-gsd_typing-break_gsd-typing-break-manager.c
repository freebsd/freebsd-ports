--- plugins/typing-break/gsd-typing-break-manager.c.orig	2008-01-14 01:20:09.000000000 +0100
+++ plugins/typing-break/gsd-typing-break-manager.c	2008-01-14 01:20:37.000000000 +0100
@@ -27,6 +27,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/signal.h>
 
 #include <locale.h>
 
