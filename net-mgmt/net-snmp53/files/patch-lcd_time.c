--- snmplib/lcd_time.c.orig	Tue Jan 25 10:16:53 2005
+++ snmplib/lcd_time.c	Tue Jan 25 10:17:10 2005
@@ -38,6 +38,9 @@
 #include <netinet/in.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
