--- src/UploadQueue.cpp.orig	Sat Oct 23 05:33:01 2004
+++ src/UploadQueue.cpp	Sat Oct 23 05:35:59 2004
@@ -19,6 +19,13 @@
 
 #include <cstring>
 #include <cmath>			// Needed for std::exp
+
+#if defined(__FreeBSD__) // for FreeBSD 4.x
+	#if __FreeBSD__ < 5
+		#include <algorithm> // needed for std::find
+	#endif
+#endif
+
 #include "types.h"
 #ifdef __WXMSW__
 	#include <winsock.h>
