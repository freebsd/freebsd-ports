--- ffmpeg/libav/rtpproto.c.orig	Mon Nov 11 18:05:59 2002
+++ ffmpeg/libav/rtpproto.c	Mon Nov 11 18:06:08 2002
@@ -16,12 +16,12 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
-#include <sys/socket.h>
 #include "avformat.h"
 
 #include <unistd.h>
 #include <stdarg.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #ifndef __BEOS__
 # include <arpa/inet.h>
