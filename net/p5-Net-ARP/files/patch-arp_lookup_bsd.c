--- arp_lookup_bsd.c.orig	2009-05-23 11:11:58 UTC
+++ arp_lookup_bsd.c
@@ -18,6 +18,8 @@ FOR A PARTICULAR PURPOSE. 
 See the GNU General Public License for more details. 
 */
 
+#include <string.h>
+#include <stdlib.h>
 #include <sys/file.h>
 #include <sys/socket.h>
 #include <net/if_dl.h>
