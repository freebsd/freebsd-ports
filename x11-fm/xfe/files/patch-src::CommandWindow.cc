--- src/CommandWindow.cc.orig	Sun Aug 15 14:28:01 2004
+++ src/CommandWindow.cc	Sun Aug 15 14:28:10 2004
@@ -13,6 +13,8 @@
 #include <stdlib.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <sys/ioctl.h>
+#include <sys/signal.h>
 #include <unistd.h>
 #include <fcntl.h>
 
