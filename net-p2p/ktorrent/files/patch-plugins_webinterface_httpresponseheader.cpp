--- plugins/webinterface/httpresponseheader.cpp.orig	2013-01-14 17:12:24 UTC
+++ plugins/webinterface/httpresponseheader.cpp
@@ -18,6 +18,8 @@
  *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
  ***************************************************************************/
 #include "httpresponseheader.h"
+#undef major
+#undef minor
 
 namespace kt
 {
