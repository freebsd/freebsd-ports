--- ./apps/artsnetagg/artsnetagg.cc.orig	Mon Oct  2 13:05:11 2000
+++ ./apps/artsnetagg/artsnetagg.cc	Wed Sep 25 16:38:09 2002
@@ -50,13 +50,18 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsFileUtil.hh"
 #include "ArtsPackageVersion.hh"
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
+#endif
+
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
 #endif
 
 extern int   errno;
