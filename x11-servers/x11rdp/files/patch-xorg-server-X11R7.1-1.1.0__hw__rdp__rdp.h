--- xorg-server-X11R7.1-1.1.0/hw/rdp/rdp.h.orig	2013-01-28 10:50:46.908229086 +0000
+++ xorg-server-X11R7.1-1.1.0/hw/rdp/rdp.h	2013-01-28 11:01:31.760225231 +0000
@@ -23,6 +23,11 @@
 #define __arm32__
 #endif
 
+#ifdef __FreeBSD__
+#undef	_POSIX_SOURCE
+#define PF_INET	AF_INET
+#endif
+
 #include "xorg-server.h"
 #include <stdio.h>
 #include <stdarg.h>
