--- libtorrent/udptracker.cpp.orig	Wed Jul 13 12:33:37 2005
+++ libtorrent/udptracker.cpp	Wed Jul 13 12:34:07 2005
@@ -18,6 +18,7 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
  ***************************************************************************/
 #include <stdlib.h>
+#include <sys/time.h>
 #include <qsocketnotifier.h>
 #include <qsocketdevice.h>
 
