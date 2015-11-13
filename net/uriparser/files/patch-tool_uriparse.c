--- tool/uriparse.c
+++ tool/uriparse.c
@@ -36,6 +36,7 @@
  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  */
+#include <sys/socket.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <uriparser/Uri.h>
