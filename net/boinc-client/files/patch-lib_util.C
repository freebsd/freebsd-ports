--- lib/util.C.orig	2007-12-28 19:58:32.000000000 +0100
+++ lib/util.C	2007-12-28 20:24:07.000000000 +0100
@@ -41,6 +41,7 @@
 #include <fstream>
 #include <cctype>
 #include <sys/types.h>
+#include <signal.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <fcntl.h>
