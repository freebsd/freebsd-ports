--- source/Irrlicht/COSOperator.cpp	2007-12-24 20:31:04.000000000 -0500
+++ source/Irrlicht/COSOperator.cpp	2007-12-24 20:37:13.000000000 -0500
@@ -10,12 +10,9 @@
 #else
 #include <string.h>
 #include <unistd.h>
-#ifdef MACOSX
-#include "OSXClipboard.h"
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
-#endif
 
 namespace irr
 {
@@ -154,7 +151,7 @@
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)
 #if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
