--- src/jpegscanhdr.cc.orig	Tue May 14 07:48:06 2002
+++ src/jpegscanhdr.cc	Wed Aug 13 10:51:43 2003
@@ -18,6 +18,10 @@
  *
  */
 
+#include <string>
+#include <vector>
+#include <assert.h>
+
 #include "jpegbase.h"
 #include "jpegscanhdr.h"
 
