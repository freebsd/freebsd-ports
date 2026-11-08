--- src/cl/include/private/Random123/features/gccfeatures.h.orig	2015-05-01 01:08:38 UTC
+++ src/cl/include/private/Random123/features/gccfeatures.h
@@ -34,17 +34,8 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 
 #define R123_GNUC_VERSION (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
 
-#if !defined(__x86_64__) && !defined(__i386__) && !defined(__powerpc__)
-#  error "This code has only been tested on x86 and powerpc platforms."
-#include <including_a_nonexistent_file_will_stop_some_compilers_from_continuing_with_a_hopeless_task>
-{ /* maybe an unbalanced brace will terminate the compilation */
- /* Feel free to try the Random123 library on other architectures by changing
- the conditions that reach this error, but you should consider it a
- porting exercise and expect to encounter bugs and deficiencies.
- Please let the authors know of any successes (or failures). */
-#endif
 
-#ifdef __powerpc__
+#if defined(__powerpc__) && !defined(__clang__)
 #include <ppu_intrinsics.h>
 #endif
 
