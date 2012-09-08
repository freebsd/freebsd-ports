--- src/base.h.orig	2012-09-07 22:48:50.000000000 -0400
+++ src/base.h	2012-09-07 22:50:59.000000000 -0400
@@ -14,6 +14,7 @@
     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
+#include <stdint.h>
 
 #ifndef H_BASE
 #define H_BASE
@@ -182,10 +183,6 @@ typedef long long itype;
 #endif //__x86_64__
 #endif //TRAPOVERFLOWS
 
-#ifndef uint64_t
-typedef unsigned long long uint64_t; //might not be right but close enough
-#endif
-
 //if we are on x86_64, we can do modular multiplication without overflow
 #ifdef __x86_64__
 #if IVALUE==ILONG
