--- ./apps/artsnets/artsnets.cc.orig	Mon Oct  2 13:05:12 2000
+++ ./apps/artsnets/artsnets.cc	Wed Sep 25 16:38:09 2002
@@ -51,14 +51,22 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsNetMatrix.hh"
 #include "ArtsIfIndexSelectionSet.hh"
 #include "ArtsTimeIntervalSelectionSet.hh"
 #include "ArtsPackageVersion.hh"
 
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
+#endif
+
+#include <string>
+
+
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
@@ -160,7 +168,7 @@
     }
   }
   
-  if (hostAttribute) {
+  if (hostAttribute != arts.Attributes().end() ) {
     inAddr.s_addr = hostAttribute->Host();
     cout << "router:  " << inet_ntoa(inAddr) << endl;
   }
