--- src/init_fnc.c.orig	Sun Nov 17 21:19:50 2002
+++ src/init_fnc.c	Sun Nov 17 21:20:39 2002
@@ -12,7 +12,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
-#include <linux/sem.h>		/* for the value of SEMVMX */
+#include <sys/ipc.h>
+#include <sys/sem.h>		/* for the value of SEMVMX */
 #include <dirent.h>
 #include <string.h>
 #include <errno.h>
