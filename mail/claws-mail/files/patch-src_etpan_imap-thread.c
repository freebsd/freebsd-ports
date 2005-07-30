--- src/etpan/imap-thread.c.orig	Sat Jul 30 11:57:41 2005
+++ src/etpan/imap-thread.c	Sat Jul 30 11:58:06 2005
@@ -8,6 +8,7 @@
 #include <imap.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <sys/wait.h>
