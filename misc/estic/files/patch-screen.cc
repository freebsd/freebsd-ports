--- spunk/bsdsrc/screen.cc.orig	Thu Nov  7 18:06:54 1996
+++ spunk/bsdsrc/screen.cc	Tue Sep  6 09:54:21 2005
@@ -22,7 +22,8 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #ifdef FREEBSD
-#    include <machine/console.h>
+#    include <sys/kbio.h>
+#    include <sys/consio.h>
 #endif
 
 #include "../screen.h"
