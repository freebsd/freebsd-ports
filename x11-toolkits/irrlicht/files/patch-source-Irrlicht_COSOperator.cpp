--- source/Irrlicht/COSOperator.cpp.orig	2009-09-19 15:58:12.000000000 +0400
+++ source/Irrlicht/COSOperator.cpp	2010-01-15 22:50:26.000000000 +0300
@@ -15,11 +15,9 @@
 #ifdef _IRR_COMPILE_WITH_OSX_DEVICE_
 #include "MacOSX/OSXClipboard.h"
 #endif
-#ifdef _IRR_OSX_PLATFORM_
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
-#endif
 
 #if defined(_IRR_COMPILE_WITH_X11_DEVICE_)
 #include "CIrrDeviceLinux.h"
@@ -184,7 +182,7 @@
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)
 #if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
