--- ffmpeg/libav/rtp.c.orig	Mon Nov 11 18:05:16 2002
+++ ffmpeg/libav/rtp.c	Mon Nov 11 18:05:24 2002
@@ -16,11 +16,11 @@
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
