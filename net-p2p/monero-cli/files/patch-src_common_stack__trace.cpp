--- src/common/stack_trace.cpp.orig	2019-11-04 14:13:39 UTC
+++ src/common/stack_trace.cpp
@@ -26,13 +26,14 @@
 // STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 // THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-#if !defined __GNUC__ || defined __MINGW32__ || defined __MINGW64__ || defined __ANDROID__
+#if !defined __GNUC__ || defined __MINGW32__ || defined __MINGW64__ || defined __ANDROID__ || defined __FreeBSD__
 #define USE_UNWIND
 #else
 #define ELPP_FEATURE_CRASH_LOG 1
 #endif
 #include "easylogging++/easylogging++.h"
 
+#include <iomanip>
 #include <stdexcept>
 #ifdef USE_UNWIND
 #define UNW_LOCAL_ONLY
