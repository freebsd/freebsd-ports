--- ./src/os_csyslogd/csyslogd.c.orig	2013-01-15 16:31:13.000000000 -0500
+++ ./src/os_csyslogd/csyslogd.c	2013-01-15 16:32:23.000000000 -0500
@@ -23,7 +23,16 @@
 #include "csyslogd.h"
 #include "os_net/os_net.h"
 
+#ifndef HAVE_STRNLEN
+size_t strnlen(char *s, size_t maxlen)
+{
+    size_t i;
 
+    for (i= 0; i < maxlen && *s != '\0'; i++, s++)
+        ;
+    return i;
+}
+#endif
 
 /* OS_SyslogD: Monitor the alerts and sends them via syslog.
  * Only return in case of error.
