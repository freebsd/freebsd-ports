--- transports/smtp/smtp.h.orig	Sun Sep 24 14:10:22 2006
+++ transports/smtp/smtp.h	Sun Sep 24 14:10:56 2006
@@ -69,6 +69,9 @@
 #include <netinet/tcp.h>
 #endif
 
+#include <sys/types.h>
+#include <openssl/md5.h>
+
 #ifndef	NFDBITS
 /*
  * This stuff taken from the 4.3bsd /usr/include/sys/types.h, but on the
