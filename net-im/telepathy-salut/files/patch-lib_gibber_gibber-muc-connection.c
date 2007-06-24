--- lib/gibber/gibber-muc-connection.c.orig	Sun Jun 24 15:48:48 2007
+++ lib/gibber/gibber-muc-connection.c	Sun Jun 24 15:49:19 2007
@@ -18,6 +18,7 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <netinet/in.h>
 
 #include <stdio.h>
 #include <stdlib.h>
