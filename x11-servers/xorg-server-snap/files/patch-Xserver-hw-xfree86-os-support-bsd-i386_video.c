Index: programs/Xserver/hw/xfree86/os-support/bsd/i386_video.c
diff -u -p programs/Xserver/hw/xfree86/os-support/bsd/i386_video.c.orig programs/Xserver/hw/xfree86/os-support/bsd/i386_video.c
--- hw/xfree86/os-support/bsd/i386_video.c.orig	Tue Oct  4 01:46:14 2005
+++ hw/xfree86/os-support/bsd/i386_video.c	Thu Jan 26 14:57:56 2006
@@ -35,6 +35,7 @@
 #include "xf86Priv.h"
 
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 #ifdef HAS_MTRR_SUPPORT
