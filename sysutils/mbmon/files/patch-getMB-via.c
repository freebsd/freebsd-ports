--- getMB-via.c.orig	Tue Dec 10 08:56:53 2002
+++ getMB-via.c	Tue Dec 10 08:59:07 2002
@@ -11,6 +11,7 @@
 #include <fcntl.h>
 
 #ifndef LINUX	/* FreeBSD */
+#include <sys/types.h>
 #include <machine/cpufunc.h>
 #define OUTb(x,y)	outb((x),(y))
 #define WAIT	outb(0xEB,0x00)
