--- ./apps/artsasagg/artsasagg.cc.orig	Mon Oct  2 13:05:10 2000
+++ ./apps/artsasagg/artsasagg.cc	Wed Sep 25 16:38:09 2002
@@ -50,15 +50,21 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-#include <map>
-
 #include "ArtsFileUtil.hh"
 #include "ArtsPackageVersion.hh"
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
+
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
+#endif
+#include <string>
+#include <map>
 
 extern int   errno;
 
