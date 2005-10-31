--- src/math_fun_jmg.hpp.orig	Mon Oct 17 10:22:04 2005
+++ src/math_fun_jmg.hpp	Sat Oct 29 21:48:25 2005
@@ -18,7 +18,15 @@
 #ifndef MATH_FUN_HPP_
 #define MATH_FUN_HPP_
 
-#include <fenv.h>
+#ifdef __cplusplus
+  extern "C" {
+#  include <fenv.h>
+#  if defined(__FreeBSD__)
+#    pragma STDC FENV_ACCESS ON
+#  endif
+}
+#endif
+
 #include "datatypes.hpp"
 #include "envt.hpp"
 #include "math_utl.hpp"
