--- tracker.cpp.orig	Sun Sep 25 03:16:19 2005
+++ tracker.cpp	Sun Sep 25 03:16:58 2005
@@ -19,6 +19,10 @@
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include <ListenSocket.h>
 #include <signal.h>
 #include "MyHandler.h"
@@ -43,6 +47,8 @@
 		fprintf(fil,"\tedge [arrowhead=open]\n");
 #ifdef _WIN32
 		std::string os = "Win32";
+#elif defined __FreeBSD__
+		std::string os = "FreeBSD";
 #else
 		std::string os = "Linux";
 #endif
