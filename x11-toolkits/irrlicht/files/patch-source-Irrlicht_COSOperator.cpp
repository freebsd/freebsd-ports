--- source/Irrlicht/COSOperator.cpp	Sun Aug 19 20:14:42 2007
+++ source/Irrlicht/COSOperator.cpp	Sun Aug 19 20:19:35 2007
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
@@ -156,7 +153,7 @@
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_) // || defined(MACOSX)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)// || defined(MACOSX)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
         long ap = sysconf(_SC_AVPHYS_PAGES);
