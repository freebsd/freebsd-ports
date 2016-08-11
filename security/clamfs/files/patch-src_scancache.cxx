--- src/scancache.cxx.orig	2016-06-17 06:02:30 UTC
+++ src/scancache.cxx
@@ -24,6 +24,7 @@
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <sys/stat.h>
 #include "scancache.hxx"
 
 namespace clamfs {
