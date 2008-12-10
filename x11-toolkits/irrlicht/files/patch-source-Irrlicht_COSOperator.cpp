---  source/Irrlicht/COSOperator.cpp	2008-12-06 13:48:20.000000000 -0500
+++  source/Irrlicht/COSOperator.cpp	2008-12-06 13:49:26.000000000 -0500
@@ -13,11 +13,9 @@
 #ifdef _IRR_USE_OSX_DEVICE_
 #include "OSXClipboard.h"
 #endif
-#ifdef _IRR_OSX_PLATFORM_
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
-#endif
 
 namespace irr
 {
@@ -157,7 +155,7 @@
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)
 #if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
