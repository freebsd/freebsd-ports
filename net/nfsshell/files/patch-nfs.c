--- nfsshell.c.orig	2013-05-10 23:40:04.000000000 +0200
+++ nfsshell.c	2013-12-28 16:34:53.000000000 +0100
@@ -70,7 +70,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/time.h>
-#include <sys/sysmacros.h>
+#include <sys/param.h>
 #include "mount.h"
 #include "nfs_prot.h"
 #include <netinet/in_systm.h>
