--- lib/gibber/gibber-linklocal-transport.c.orig	Thu Apr 19 16:56:03 2007
+++ lib/gibber/gibber-linklocal-transport.c	Thu Apr 19 17:06:11 2007
@@ -18,6 +18,9 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -196,7 +199,13 @@
   if (s6->sin6_family == AF_INET6 && IN6_IS_ADDR_V4MAPPED(&(s6->sin6_addr))) {
     /* Normalize to ipv4 address */
     s4->sin_family = AF_INET;
+#if defined(__Linux__)
     s4->sin_addr.s_addr = s6->sin6_addr.s6_addr32[3];
+#elif defined(__FreeBSD__)
+    s4->sin_addr.s_addr = s6->sin6_addr.__u6_addr.__u6_addr32[3];
+#else
+#error XXX - fill in the blanks.    
+#endif
   }
   return success;
 }
