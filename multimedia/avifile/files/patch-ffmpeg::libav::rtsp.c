--- ffmpeg/libav/rtsp.c.orig	Mon Nov 11 18:06:37 2002
+++ ffmpeg/libav/rtsp.c	Mon Nov 11 18:06:51 2002
@@ -16,11 +16,12 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
-#include <netinet/in.h>
 #include "avformat.h"
 
 #include <sys/time.h>
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #ifndef __BEOS__
 # include <arpa/inet.h>
 #else
