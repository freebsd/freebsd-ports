--- cmake/FindConsoleKit.cmake.orig	2021-05-19 07:41:26 UTC
+++ cmake/FindConsoleKit.cmake
@@ -25,7 +25,7 @@
 # THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 #=============================================================================
 find_program(cklistsessions_EXECUTABLE NAMES ck-list-sessions)
-find_program(qdbus_EXECUTABLE NAMES qdbus)
+find_program(qdbus_EXECUTABLE NAMES qdbus-qt5 qdbus)
 find_package_handle_standard_args(ConsoleKit
     FOUND_VAR
         ConsoleKit_FOUND
