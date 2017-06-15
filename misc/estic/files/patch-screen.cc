--- spunk/bsdsrc/screen.cc.orig	1996-11-07 17:06:54 UTC
+++ spunk/bsdsrc/screen.cc
@@ -22,7 +22,8 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #ifdef FREEBSD
-#    include <machine/console.h>
+#    include <sys/kbio.h>
+#    include <sys/consio.h>
 #endif
 
 #include "../screen.h"
