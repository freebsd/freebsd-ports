--- getMB-isa.c.orig	Tue Dec 10 08:56:28 2002
+++ getMB-isa.c	Tue Dec 10 08:57:21 2002
@@ -8,6 +8,7 @@
 #include <fcntl.h>
 
 #ifndef LINUX	/* FreeBSD */
+#include <sys/types.h>
 #include <machine/cpufunc.h>
 #define OUTb(x,y)	outb((x),(y))
 #define WAIT	outb(0xEB,0x00)
