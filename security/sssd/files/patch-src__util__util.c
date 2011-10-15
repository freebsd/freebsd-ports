--- ./src/util/util.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/util.c	2011-10-13 12:15:03.000000000 -0400
@@ -18,6 +18,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/socket.h>
 #include <ctype.h>
 #include <netdb.h>
 
