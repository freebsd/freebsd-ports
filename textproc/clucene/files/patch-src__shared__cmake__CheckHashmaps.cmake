--- src/shared/cmake/CheckHashmaps.cmake.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/shared/cmake/CheckHashmaps.cmake	2014-06-24 19:20:14.000000000 -0400
@@ -35,8 +35,12 @@
 #elif defined(_CL_HAVE_EXT_HASH_MAP)
 	#include <ext/hash_map>
 #elif defined(_CL_HAVE_TR1_UNORDERED_MAP)
+#if defined(_LIBCPP_VERSION)
+	#include <unordered_map>
+#else
 	#include <tr1/unordered_map>
 #endif
+#endif
 int main() {  
     ${namespace}::${_CL_HASH_MAP}<int,char> a; 
     return 0; 
