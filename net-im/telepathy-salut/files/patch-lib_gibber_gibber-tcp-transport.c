--- lib/gibber/gibber-tcp-transport.c.orig	Thu Apr 19 16:54:23 2007
+++ lib/gibber/gibber-tcp-transport.c	Thu Apr 19 16:54:46 2007
@@ -18,6 +18,7 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <netinet/in.h>
 
 #include <stdio.h>
 #include <stdlib.h>
