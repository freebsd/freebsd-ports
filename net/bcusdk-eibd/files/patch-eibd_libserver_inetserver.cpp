--- eibd/libserver/inetserver.cpp.orig	2007-11-08 15:31:33.000000000 +0000
+++ eibd/libserver/inetserver.cpp	2007-12-08 15:29:25.000000000 +0000
@@ -17,11 +17,11 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <unistd.h>
-#include <string.h>
 #include "inetserver.h"
 
 InetServer::InetServer (Layer3 * la3, Trace * tr, int port):
