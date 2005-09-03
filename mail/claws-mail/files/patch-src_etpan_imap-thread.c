--- src/etpan/imap-thread.c.orig	Fri Jul 22 13:30:23 2005
+++ src/etpan/imap-thread.c	Sat Sep  3 11:05:25 2005
@@ -6,8 +6,10 @@
 
 #include "imap-thread.h"
 #include <imap.h>
+#include <pthread.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <sys/wait.h>
