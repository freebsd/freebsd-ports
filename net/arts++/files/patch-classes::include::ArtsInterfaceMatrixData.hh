--- ./classes/include/ArtsInterfaceMatrixData.hh.orig	Mon Oct  2 13:05:16 2000
+++ ./classes/include/ArtsInterfaceMatrixData.hh	Wed Sep 25 16:38:10 2002
@@ -44,15 +44,17 @@
 #define ARTSINTERFACEMATRIXDATA_HH_
 
 extern "C" {
+#include "artslocal.h"
 #include "caida_t.h"
 }
 
 #include <vector>
 
 #ifdef HAVE_IOSTREAM
-  #include <iostream>
+#  include <iostream>
+   using namespace std;
 #else
-  #include <iostream.h>
+#  include <iostream.h>
 #endif
 #include <algorithm>
 
