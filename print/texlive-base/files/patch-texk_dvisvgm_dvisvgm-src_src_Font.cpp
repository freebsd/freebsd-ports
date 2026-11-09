--- texk/dvisvgm/dvisvgm-src/src/Font.cpp.orig	2026-01-19 23:07:15 UTC
+++ texk/dvisvgm/dvisvgm-src/src/Font.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include <algorithm>
 #include <cstdlib>
 #include <set>
