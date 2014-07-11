--- src/node_constants.orig 2014-06-24 23:09:52.432840733 -0300
+++ src/node_constants.cc 2014-06-24 10:07:23.406890824 -0300
@@ -19,13 +19,13 @@
 // OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 // USE OR OTHER DEALINGS IN THE SOFTWARE.
 
-// O_NONBLOCK is not exported unless _XOPEN_SOURCE >= 500.
-#if defined(_XOPEN_SOURCE) && _XOPEN_SOURCE < 500
-#undef _XOPEN_SOURCE
+// O_NONBLOCK is not exported unless _XOPEN_SOURCE >= 600.
+#if defined(_XOPEN_SOURCE) && _XOPEN_SOURCE < 600
+# undef _XOPEN_SOURCE
 #endif
 
 #if !defined(_XOPEN_SOURCE)
-#define _XOPEN_SOURCE 500
+# define _XOPEN_SOURCE 600
 #endif
 
 #include "node_constants.h"
