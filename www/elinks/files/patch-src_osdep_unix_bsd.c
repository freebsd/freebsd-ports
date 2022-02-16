--- src/osdep/unix/bsd.c.orig	2022-01-29 20:03:00 UTC
+++ src/osdep/unix/bsd.c
@@ -15,6 +15,10 @@
 #endif	/* HAVE_SYS_CONSIO_H */
 #endif	/* CONFIG_SYSMOUSE */
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #include "elinks.h"
 
 #include "main/select.h"
