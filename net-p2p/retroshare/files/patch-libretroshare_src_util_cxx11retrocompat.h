--- libretroshare/src/util/cxx11retrocompat.h.orig	2017-07-31 06:26:46 UTC
+++ libretroshare/src/util/cxx11retrocompat.h
@@ -17,7 +17,7 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

-#ifdef __GNUC__
+#if defined __GNUC__ and not defined  __clang__
 #	define GCC_VERSION (__GNUC__*10000+__GNUC_MINOR__*100+__GNUC_PATCHLEVEL__)
 #	if GCC_VERSION < 40700
 #		define override

