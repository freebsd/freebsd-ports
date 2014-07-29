--- voxware.h.orig	Sat Sep  7 16:51:45 2002
+++ voxware.h	Sat Sep  7 16:51:58 2002
@@ -30,9 +30,7 @@
 #ifndef __VOXWARE_H
 #define __VOXWARE_H
 
-#if defined(__FreeBSD__)
-#  include <machine/soundcard.h>
-#elif defined(linux) || defined(__bsdi__)
+#if defined(linux) || defined(__bsdi__) || defined(__FreeBSD__)
 #  include <sys/soundcard.h>
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 #  include <soundcard.h>
