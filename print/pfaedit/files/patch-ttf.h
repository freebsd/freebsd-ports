--- pfaedit/ttf.h.orig	Thu Dec 20 13:29:41 2001
+++ pfaedit/ttf.h	Thu Dec 20 13:29:58 2001
@@ -24,7 +24,8 @@
  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
- 
+
+#include <sys/types.h> 
 #include "psfont.h"		/* for struct fddata */
 
 /* Some glyphs have multiple encodings ("A" might be used for Alpha and Cyrillic A) */
