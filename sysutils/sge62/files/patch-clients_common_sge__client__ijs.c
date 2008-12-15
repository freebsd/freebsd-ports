
$FreeBSD$

--- clients/common/sge_client_ijs.c.orig
+++ clients/common/sge_client_ijs.c
@@ -36,7 +36,7 @@
 #include <signal.h>
 #include <string.h>
 
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(FREEBSD)
 #  include <termios.h>
 #  include <sys/ttycom.h>
 #  include <sys/ioctl.h>
