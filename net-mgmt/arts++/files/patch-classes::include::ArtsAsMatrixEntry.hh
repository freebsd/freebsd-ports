--- ./classes/include/ArtsAsMatrixEntry.hh.orig	Mon Oct  2 13:05:14 2000
+++ ./classes/include/ArtsAsMatrixEntry.hh	Wed Sep 25 16:38:10 2002
@@ -50,7 +50,12 @@
 #include "caida_t.h"
 }
 
-#include <ostream.h>
+#ifdef HAVE_IOSTREAM
+# include <iostream>
+  using namespace std;
+#else
+# include <iostream.h>
+#endif
 
 #ifdef HAVE_IOMANIP
   #include <iomanip>
