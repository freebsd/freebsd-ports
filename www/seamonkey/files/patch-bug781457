--- mozilla/xpcom/base/nsStackWalk.cpp~
+++ mozilla/xpcom/base/nsStackWalk.cpp
@@ -1638,6 +1638,7 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
+#define _GNU_SOURCE
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
 #include <unwind.h>
 
