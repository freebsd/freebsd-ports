--- spf.h.orig	Fri May 14 18:49:30 2004
+++ spf.h	Fri May 21 17:13:30 2004
@@ -47,6 +47,7 @@
 #define	_SPF_H 1
 
 #include <sys/types.h>    /* typedefs */
+#include <netinet/in.h>
 #include <arpa/inet.h>    /* in_addr struct */
 
 __BEGIN_DECLS
