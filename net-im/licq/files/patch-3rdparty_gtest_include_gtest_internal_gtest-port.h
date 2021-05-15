--- 3rdparty/gtest/include/gtest/internal/gtest-port.h.orig	2014-10-22 20:07:20 UTC
+++ 3rdparty/gtest/include/gtest/internal/gtest-port.h
@@ -141,6 +141,10 @@
 //   GTEST_DISALLOW_COPY_AND_ASSIGN_ - disables copy ctor and operator=.
 //   GTEST_MUST_USE_RESULT_   - declares that a function's result must be used.
 //
+// C++11 feature wrappers:
+//
+//   GTEST_MOVE_          - portability wrapper for std::move.
+//
 // Synchronization:
 //   Mutex, MutexLock, ThreadLocal, GetThreadCount()
 //                  - synchronization primitives.
@@ -211,6 +215,7 @@
 #include <iostream>  // NOLINT
 #include <sstream>  // NOLINT
 #include <string>  // NOLINT
+#include <utility>
 
 #define GTEST_DEV_EMAIL_ "googletestframework@@googlegroups.com"
 #define GTEST_FLAG_PREFIX_ "gtest_"
@@ -737,6 +742,12 @@ using ::std::tuple_size;
 #else
 # define GTEST_MUST_USE_RESULT_
 #endif  // __GNUC__ && (GTEST_GCC_VER_ >= 30400) && !COMPILER_ICC
+
+#if GTEST_LANG_CXX11
+# define GTEST_MOVE_(x) ::std::move(x)  // NOLINT
+#else
+# define GTEST_MOVE_(x) x
+#endif
 
 // Determine whether the compiler supports Microsoft's Structured Exception
 // Handling.  This is supported by several Windows compilers but generally
