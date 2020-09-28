--- lib/gibber/gibber-muc-connection.c.orig	2012-11-12 14:13:18 UTC
+++ lib/gibber/gibber-muc-connection.c
@@ -18,6 +18,7 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <netinet/in.h>
 
 #include <stdio.h>
 #include <stdlib.h>
