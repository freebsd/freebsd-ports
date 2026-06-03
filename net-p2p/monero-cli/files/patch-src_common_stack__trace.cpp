--- src/common/stack_trace.cpp.orig	2025-10-07 19:25:41 UTC
+++ src/common/stack_trace.cpp
@@ -26,7 +26,7 @@
 // STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 // THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-#if !defined __GNUC__ || defined __MINGW32__ || defined __MINGW64__ || defined __ANDROID__
+#if !defined __GNUC__ || defined __MINGW32__ || defined __MINGW64__ || defined __ANDROID__ || defined __FreeBSD__
 #define USE_UNWIND
 #else
 #define ELPP_FEATURE_CRASH_LOG 1
