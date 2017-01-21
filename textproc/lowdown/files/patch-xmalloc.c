--- xmalloc.c.orig	2017-01-20 14:49:54 UTC
+++ xmalloc.c
@@ -14,6 +14,8 @@
  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
+#include <sys/param.h>
+
 #include <err.h>
 #include <stdarg.h>
 #include <stdint.h>
@@ -64,7 +66,7 @@ void *
 xreallocarray(void *p, size_t nm, size_t sz)
 {
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || (defined(__FreeBSD__) && __FreeBSD_version > 1100071)
 	if ((p = reallocarray(p, nm, sz)) == NULL)
 		err(EXIT_FAILURE, NULL);
 #else
