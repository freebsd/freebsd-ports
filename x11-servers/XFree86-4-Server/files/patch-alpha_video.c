$FreeBSD: /tmp/pcvs/ports/x11-servers/XFree86-4-Server/files/Attic/patch-alpha_video.c,v 1.3 2004-08-10 01:29:21 marcus Exp $

--- programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c.orig	Wed Feb 25 11:04:10 2004
+++ programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c	Wed Feb 25 11:04:50 2004
@@ -483,7 +483,7 @@
 writeSparse32(int Value, pointer Base, register unsigned long Offset);
 
 #ifdef __FreeBSD__
-extern int sysarch(int, char *);
+extern int sysarch(int, void *);
 #endif
 
 struct parms {
