--- icmp.h	Fri Nov 23 17:50:51 2001
+++ icmp.h	Tue Mar  5 22:16:25 2002
@@ -3,13 +3,8 @@
 #ifndef _SENDIP_ICMP_H
 #define _SENDIP_ICMP_H
 
-/* FreeBSD needs these.  It shouldn't, but it does.  GRR */
-#include <netinet/in_systm.h>
-#include <netinet/ip.h>
-
-/* For message types */
-#include <netinet/ip_icmp.h>
-#include <netinet/icmp6.h>
+#define ICMP6_ECHO_REQUEST 128
+#define ICMP_ECHO          8
 
 /* ICMP HEADER
  * Copied from glibc 2.2, reproduced here without code specific stuff
