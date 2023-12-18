--- src/scrun/srun.c.orig	2023-03-28 20:15:54 UTC
+++ src/scrun/srun.c
@@ -40,7 +40,9 @@
 
 #include <fcntl.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <sys/prctl.h>
+#endif
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <termios.h>
