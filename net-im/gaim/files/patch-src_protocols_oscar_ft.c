--- src/protocols/oscar/ft.c.orig	Sat Jan 10 14:05:46 2004
+++ src/protocols/oscar/ft.c	Sat Jan 10 14:07:58 2004
@@ -49,6 +49,7 @@
 #ifndef _WIN32
 #include <stdio.h>
 #include <netdb.h>
+#include <limits.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/utsname.h> /* for aim_odc_initiate */
