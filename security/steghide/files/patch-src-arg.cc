--- src/arg.cc.orig	Thu Sep 26 19:18:45 2002
+++ src/arg.cc	Thu Sep 26 19:18:48 2002
@@ -18,6 +18,7 @@
  *
  */
 
+#include <string>
 #include "arg.h"
 
 template<class T> Arg<T>::Arg (void)
