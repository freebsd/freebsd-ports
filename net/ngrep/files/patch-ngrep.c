--- ngrep.c.orig	Tue Apr 11 09:20:31 2006
+++ ngrep.c	Tue Apr 11 09:20:59 2006
@@ -15,6 +15,7 @@
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <net/if.h>
+#include <arpa/inet.h>
 #include <sys/tty.h>
 #include <pwd.h>
 #endif
