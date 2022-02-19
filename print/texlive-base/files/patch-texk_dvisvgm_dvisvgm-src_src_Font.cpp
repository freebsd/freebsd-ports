--- texk/dvisvgm/dvisvgm-src/src/Font.cpp.orig	2022-01-29 15:59:04 UTC
+++ texk/dvisvgm/dvisvgm-src/src/Font.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <set>
