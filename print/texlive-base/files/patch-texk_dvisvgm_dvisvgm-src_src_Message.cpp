--- texk/dvisvgm/dvisvgm-src/src/Message.cpp.orig	2022-01-29 16:06:37 UTC
+++ texk/dvisvgm/dvisvgm-src/src/Message.cpp
@@ -18,6 +18,7 @@
 ** along with this program; if not, see <http://www.gnu.org/licenses/>. **
 *************************************************************************/
 
+#include <sys/time.h>
 #include <cstdarg>
 #include <cstdlib>
 #include <cstring>
