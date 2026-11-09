--- texk/dvisvgm/dvisvgm-src/src/FontEncoding.cpp.orig	2026-01-19 23:07:15 UTC
+++ texk/dvisvgm/dvisvgm-src/src/FontEncoding.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include "CMap.hpp"
 #include "CMapManager.hpp"
 #include "EncFile.hpp"
