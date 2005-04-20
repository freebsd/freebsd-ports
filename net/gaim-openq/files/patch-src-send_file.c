--- src/send_file.c.orig	Thu Dec 23 06:22:22 2004
+++ src/send_file.c	Wed Apr 20 13:16:55 2005
@@ -22,6 +22,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <sys/socket.h>
 #include <network.h>
 
 #include "send_file.h"
