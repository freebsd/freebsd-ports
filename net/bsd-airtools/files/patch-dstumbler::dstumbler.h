--- dstumbler/dstumbler.h.orig	Sat Jul  6 14:57:30 2002
+++ dstumbler/dstumbler.h	Sat Jul  6 14:57:48 2002
@@ -47,7 +47,7 @@
 #include <net/if.h>
 #include <sys/termios.h>
 
-#include <bat/common.h>
+#include <dev/wi/if_wavelan_ieee.h>
 
 #ifdef __OpenBSD__
 #include <curses.h>
