--- src/satip/server.c.orig	2015-09-25 13:57:59 UTC
+++ src/satip/server.c
@@ -17,6 +17,8 @@
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <sys/socket.h>
+
 #include "tvheadend.h"
 #include "upnp.h"
 #include "settings.h"
