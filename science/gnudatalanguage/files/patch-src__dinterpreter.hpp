--- src/dinterpreter.hpp.orig	Mon Oct 17 10:22:04 2005
+++ src/dinterpreter.hpp	Sat Oct 29 21:46:46 2005
@@ -25,7 +25,14 @@
 #include <fstream>
 #include <csignal>
 
-#include <fenv.h>
+#ifdef __cplusplus
+  extern "C" {
+#  include <fenv.h>
+#  if defined(__FreeBSD__)
+#    pragma STDC FENV_ACCESS ON
+#  endif
+}
+#endif
 
 #include "initsysvar.hpp"
 #include "objects.hpp"
