--- ./classes/include/ArtsNetMatrixData.hh.orig	Mon Oct  2 13:05:17 2000
+++ ./classes/include/ArtsNetMatrixData.hh	Wed Sep 25 16:38:10 2002
@@ -44,12 +44,19 @@
 #define ARTSNETMATRIXDATA_HH_
 
 extern "C" {
+#include "artslocal.h"
 #include "caida_t.h"
 }
 
 #include <vector>
-#include <istream.h>
-#include <ostream.h>
+
+#ifdef HAVE_IOSTREAM
+# include <iostream>
+using namespace std;
+#else
+# include <istream.h>
+# include <ostream.h>
+#endif
 
 #include "ArtsNetMatrixEntry.hh"
 
