--- libtorrent/udptrackersocket.cpp.orig	Mon Oct 10 20:18:17 2005
+++ libtorrent/udptrackersocket.cpp	Mon Oct 10 20:19:22 2005
@@ -17,6 +17,7 @@
  *   Free Software Foundation, Inc.,                                       *
  *   51 Franklin Steet, Fifth Floor, Boston, MA 02110-1301, USA.             *
  ***************************************************************************/
+#include <sys/time.h>
 #include <stdlib.h>
 #include <libutil/array.h>
 #include <qsocketdevice.h>
