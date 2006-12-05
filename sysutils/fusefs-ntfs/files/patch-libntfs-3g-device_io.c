--- libntfs-3g/device_io.c.orig	Wed Dec  6 04:03:06 2006
+++ libntfs-3g/device_io.c	Tue Dec  5 23:04:04 2006
@@ -26,7 +26,11 @@
 #ifndef __CYGWIN32__
 
 /* Not on Cygwin; use standard Unix style low level device operations. */
+#if defined(__FreeBSD__)
+#include "unix_io_raw.c"
+#else
 #include "unix_io.c"
+#endif
 
 #else /* __CYGWIN32__ */
 
