--- texk/dvisvgm/dvisvgm-src/src/FontEncoding.cpp.orig	2022-01-29 16:03:07 UTC
+++ texk/dvisvgm/dvisvgm-src/src/FontEncoding.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include "CMap.hpp"
 #include "CMapManager.hpp"
 #include "EncFile.hpp"
