Index: bgpd/util.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/util.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/util.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/util.c	30 Jun 2009 06:40:07 -0000	1.2
@@ -18,6 +18,9 @@
  */
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__)	/* sys/limits.h */
+#include <sys/limits.h>
+#endif /* defined(__FreeBSD__) */
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
