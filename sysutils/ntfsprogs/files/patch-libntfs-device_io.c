--- libntfs/device_io.c.orig	Wed Dec  6 03:57:01 2006
+++ libntfs/device_io.c	Wed Dec  6 03:05:24 2006
@@ -26,7 +26,11 @@
 #ifndef __CYGWIN32__
 
 /* Not on Cygwin; use standard Unix style low level device operations. */
+#if defined(__FreeBSD__)
+#include "unix_io_raw.c"
+#else
 #include "unix_io.c"
+#endif
 
 #else /* __CYGWIN32__ */
 
