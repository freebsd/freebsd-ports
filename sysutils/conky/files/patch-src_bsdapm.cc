--- src/bsdapm.cc.orig	2016-10-04 07:49:19 UTC
+++ src/bsdapm.cc
@@ -27,6 +27,10 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  *
  */
+
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+	|| defined(__DragonFly__) \
+	|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
 #include "config.h"
 #include "conky.h"
 #include "text_object.h"
@@ -208,3 +212,4 @@ void print_apm_battery_time(struct text_
 	}
 #endif
 }
+#endif
