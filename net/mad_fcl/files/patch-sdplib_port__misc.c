
$FreeBSD$

--- sdplib/port_misc.c.orig	Fri Jun 25 13:29:37 2004
+++ sdplib/port_misc.c	Fri Jun 25 13:31:13 2004
@@ -47,6 +47,7 @@
 #  include <sys/unistd.h>
 #endif
 
+#define HAVE_UNISTD_H
 #if defined (HAVE_UNISTD_H)
 #  include <unistd.h>
 #endif
@@ -55,6 +56,9 @@
 #  include <syslog.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/time.h>
+#define HAVE_SYS_SELECT_H
 #if defined (HAVE_SYS_SELECT_H)
 #  include <sys/select.h>
 #endif
