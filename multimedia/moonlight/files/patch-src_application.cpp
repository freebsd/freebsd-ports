
$FreeBSD$

--- src/application.cpp.orig
+++ src/application.cpp
@@ -17,6 +17,10 @@
 #include <fcntl.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
+
 #include "application.h"
 #include "runtime.h"
 #include "deployment.h"
@@ -369,4 +373,4 @@
 		Deployment::GetCurrent()->TrackPath (resource_root);
 	}
 	return resource_root;
-}
\ No newline at end of file
+}
