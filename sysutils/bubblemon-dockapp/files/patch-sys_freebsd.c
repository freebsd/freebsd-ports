--- sys_freebsd.c.orig	Mon Apr 16 14:14:53 2001
+++ sys_freebsd.c	Sat Feb  1 11:39:45 2003
@@ -19,6 +19,7 @@
 
 #include <kvm.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/dkstat.h>
 #include <sys/vmmeter.h>
 #include <stdlib.h>
