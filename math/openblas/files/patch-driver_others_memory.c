Passing a priority level to constructor/destructor only works on GCC >= 4.3.0;
improve the upstream check so that the build works with base GCC.
--- driver/others/memory.c.orig	2016-04-12 19:29:19 UTC
+++ driver/others/memory.c
@@ -144,7 +144,7 @@ USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 #if defined(_MSC_VER) && !defined(__clang__)
 #define CONSTRUCTOR __cdecl
 #define DESTRUCTOR __cdecl
-#elif (defined(OS_DARWIN) || defined(OS_SUNOS)) && defined(C_GCC)
+#elif (defined(OS_DARWIN) || defined(OS_SUNOS)) || (defined(C_GCC) && ((__GNUC__ == 4) && (__GNUC_MINOR__ < 3)))
 #define CONSTRUCTOR	__attribute__ ((constructor))
 #define DESTRUCTOR	__attribute__ ((destructor))
 #else
