
$FreeBSD$

--- clients/qsh/qsh.c.orig
+++ clients/qsh/qsh.c
@@ -85,7 +85,7 @@
 
 #include "gdi/sge_gdi_ctx.h"
 
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(FREEBSD)
 #  include <termios.h>
 #  include <sys/ttycom.h>
 #  include <sys/ioctl.h>
