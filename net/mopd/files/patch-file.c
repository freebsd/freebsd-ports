--- common/file.c.orig	Fri Aug 16 15:39:41 1996
+++ common/file.c	Wed Jul  7 01:27:32 2004
@@ -45,4 +45,5 @@
 #if defined(__FreeBSD__)
 #include <sys/imgact_aout.h>
+#include <sys/endian.h>
 #endif
 #if !defined(MID_VAX)
