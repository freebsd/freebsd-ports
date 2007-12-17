--- eibd/client/c/openremote.c.orig	2007-11-08 15:31:32.000000000 +0000
+++ eibd/client/c/openremote.c	2007-12-08 15:23:07.000000000 +0000
@@ -25,6 +25,7 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
