--- libobs/util/platform-nix.c.orig	2015-03-27 21:29:37 UTC
+++ libobs/util/platform-nix.c
@@ -26,8 +26,10 @@
 
 #if !defined(__APPLE__)
 #include <sys/times.h>
+#if !defined(__FreeBSD__)
 #include <sys/vtimes.h>
 #endif
+#endif
 
 #include "darray.h"
 #include "dstr.h"
