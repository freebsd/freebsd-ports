--- ffmpeg/libav/http.c.orig	Mon Nov 11 18:03:57 2002
+++ ffmpeg/libav/http.c	Mon Nov 11 18:04:09 2002
@@ -16,11 +16,11 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include "avformat.h"
 #include <unistd.h>
 #include <ctype.h>
-#include <sys/types.h>
 #include <netinet/in.h>
 #ifndef __BEOS__
 # include <arpa/inet.h>
