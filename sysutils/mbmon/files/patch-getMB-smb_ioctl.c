$FreeBSD$

--- getMB-smb_ioctl.c.orig	Sat Jul  5 18:15:24 2003
+++ getMB-smb_ioctl.c	Fri Dec 16 17:56:54 2005
@@ -5,6 +5,7 @@
 #ifdef HAVE_SMBUS
 /* assume SMBus ioctl support, only for FreeBSD */
 
+#include <sys/param.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <fcntl.h>
@@ -13,7 +14,11 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 
+#if __FreeBSD_version >= 500000
+#include <dev/smbus/smb.h>
+#else
 #include <machine/smb.h>
+#endif
 
 #include "methods.h"
 
