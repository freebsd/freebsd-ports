--- ./src/kuserok.c.orig	2011-07-29 15:31:01.000000000 -0400
+++ ./src/kuserok.c	2011-10-18 11:46:19.000000000 -0400
@@ -36,6 +36,7 @@
 #include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <grp.h>
