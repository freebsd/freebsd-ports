--- arp_lookup_bsd.c.orig	2006-09-20 11:19:00.000000000 +0200
+++ arp_lookup_bsd.c	2008-06-24 14:57:10.000000000 +0200
@@ -18,6 +18,8 @@
 See the GNU General Public License for more details. 
 */
 
+#include <string.h>
+#include <stdlib.h>
 #include <sys/file.h>
 #include <sys/socket.h>
 #include <net/if_dl.h>
