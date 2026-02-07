--- yt/utilities/lib/platform_dep_math.hpp.orig	2021-08-02 20:38:53 UTC
+++ yt/utilities/lib/platform_dep_math.hpp
@@ -5,6 +5,7 @@ MSVC does not define isnormal in the std:: namespace, 
 However with GCC-5, there is a clash between the definition of isnormal in <math.h> and using C++14, so we need to import from cmath instead.
 */
 
+#if !defined(__FreeBSD__) // see https://github.com/yt-project/yt/issues/3459
 #if _MSC_VER
 #include <math.h>
 inline bool __isnormal(double x) {
@@ -15,4 +16,5 @@ inline bool __isnormal(double x) {
 inline bool __isnormal(double x) {
     return std::isnormal(x);
 }
+#endif
 #endif
