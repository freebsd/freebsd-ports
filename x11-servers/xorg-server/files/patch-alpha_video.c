--- programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c.orig	Wed Sep  1 21:05:09 2004
+++ programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c	Wed Sep  1 21:06:52 2004
@@ -487,7 +487,7 @@
 writeSparse32(int Value, pointer Base, register unsigned long Offset);
 
 #ifdef __FreeBSD__
-extern int sysarch(int, char *);
+extern int sysarch(int, void *);
 #endif
 
 struct parms {
