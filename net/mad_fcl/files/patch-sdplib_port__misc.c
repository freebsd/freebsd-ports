
$FreeBSD$

--- sdplib/port_misc.c.orig
+++ sdplib/port_misc.c
@@ -47,6 +47,7 @@
 #  include <sys/unistd.h>
 #endif
 
+#define HAVE_UNISTD_H
 #if defined (HAVE_UNISTD_H)
 #  include <unistd.h>
 #endif
@@ -54,6 +55,10 @@
 #if defined (HAVE_SYSLOG_H)
 #  include <syslog.h>
 #endif
+
+#include <sys/types.h>
+#include <sys/time.h>
+#define HAVE_SYS_SELECT_H
 
 #if defined (HAVE_SYS_SELECT_H)
 #  include <sys/select.h>
