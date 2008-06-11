
$FreeBSD$

--- daemons/shepherd/sge_shepherd_ijs.c.orig
+++ daemons/shepherd/sge_shepherd_ijs.c
@@ -45,7 +45,7 @@
 #include <sys/timeb.h>
 #include <sys/resource.h>
 
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(FREEBSD)
 #  include <termios.h>
 #  include <sys/ttycom.h>
 #  include <sys/ioctl.h>
