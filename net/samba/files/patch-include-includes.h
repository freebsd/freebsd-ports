--- include/includes.h.orig	Sat Oct 13 17:09:21 2001
+++ include/includes.h	Fri Jan 11 22:12:06 2002
@@ -27,6 +27,11 @@
 
 #include "local.h"
 
+#ifdef __FreeBSD__
+#define DEFAULT_PRINTING PRINT_BSD
+#define PRINTCAP_NAME "/etc/printcap"
+#endif /* __FreeBSD__ */
+
 #ifdef AIX
 #define DEFAULT_PRINTING PRINT_AIX
 #define PRINTCAP_NAME "/etc/qconfig"
