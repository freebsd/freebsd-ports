--- ./classes/include/ArtsRttTimeSeriesTableData.hh.orig	Thu Oct 19 19:37:14 2000
+++ ./classes/include/ArtsRttTimeSeriesTableData.hh	Wed Sep 25 16:38:10 2002
@@ -47,7 +47,15 @@
 #include <sys/time.h>
 
 #include "caida_t.h"
+#include "artslocal.h"
 }
+
+#ifdef HAVE_IOSTREAM
+# include <iostream>
+  using namespace std;
+#else
+# include <iostream.h>
+#endif
 
 #include <vector>
 
