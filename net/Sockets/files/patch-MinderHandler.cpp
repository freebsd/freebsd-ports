--- MinderHandler.cpp.orig	Sun Apr  3 18:42:07 2005
+++ MinderHandler.cpp	Sun Apr  3 18:43:09 2005
@@ -20,6 +20,10 @@
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef _WIN32
 #pragma warning(disable:4786)
 #endif
@@ -428,6 +432,8 @@
 	msg += ":" + tmp;
 #ifdef _WIN32
 	msg += ":Win32";
+#elif defined __FreeBSD__
+	msg += ":FreeBSD";
 #else
 	msg += ":Linux";
 #endif
