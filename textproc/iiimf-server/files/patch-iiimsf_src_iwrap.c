--- src/iwrap.c.orig	Sat Dec  6 02:44:54 2003
+++ src/iwrap.c	Sat Dec  6 02:45:05 2003
@@ -51,6 +51,7 @@
 #include <tcpd.h>
 #endif
 
+#include <sys/types.h>
 #ifdef HAVE_PAM
 #include <security/pam_appl.h>
 #endif
