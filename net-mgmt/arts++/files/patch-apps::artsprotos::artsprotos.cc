--- ./apps/artsprotos/artsprotos.cc.orig	Mon Oct  2 13:05:13 2000
+++ ./apps/artsprotos/artsprotos.cc	Wed Sep 25 16:38:09 2002
@@ -52,14 +52,22 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsProtocolTable.hh"
 #include "ArtsIfIndexSelectionSet.hh"
 #include "ArtsTimeIntervalSelectionSet.hh"
 #include "ArtsPackageVersion.hh"
 
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+#else
+# include <fstream.h>
+#endif 
+
+#include <string>
+using namespace std;
+
+
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
@@ -118,7 +126,7 @@
     }
   }
   
-  if (hostAttribute) {
+  if (hostAttribute != arts.Attributes().end() ) {
     inAddr.s_addr = hostAttribute->Host();
     cout << "router:  " << inet_ntoa(inAddr) << endl;
   }
