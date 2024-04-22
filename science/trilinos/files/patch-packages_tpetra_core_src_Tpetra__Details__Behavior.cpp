- workaround for https://github.com/trilinos/Trilinos/issues/12890

--- packages/tpetra/core/src/Tpetra_Details_Behavior.cpp.orig	2024-04-04 21:39:32 UTC
+++ packages/tpetra/core/src/Tpetra_Details_Behavior.cpp
@@ -40,6 +40,7 @@
 */
 // clang-format on
 #include <algorithm> // std::transform
+#include <array>
 #include <cctype>    // std::toupper
 #include <cstdlib>   // std::getenv
 #include <functional>
