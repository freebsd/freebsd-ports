--- texk/dvisvgm/dvisvgm-src/src/Message.cpp.orig	2025-01-12 14:58:51 UTC
+++ texk/dvisvgm/dvisvgm-src/src/Message.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include <cstdarg>
 #include <cstdlib>
 #include <cstring>
