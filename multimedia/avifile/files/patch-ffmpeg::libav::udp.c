--- ffmpeg/libav/udp.c.orig	Mon Nov 11 18:07:52 2002
+++ ffmpeg/libav/udp.c	Mon Nov 11 18:07:56 2002
@@ -16,10 +16,10 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
-#include <sys/socket.h>
 #include "avformat.h"
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #ifndef __BEOS__
 # include <arpa/inet.h>
