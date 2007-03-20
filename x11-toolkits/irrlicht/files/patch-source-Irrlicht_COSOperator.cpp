--- source/Irrlicht/COSOperator.cpp	Tue Mar 20 09:46:39 2007
+++ source/Irrlicht/COSOperator.cpp	Tue Mar 20 09:50:49 2007
@@ -13,6 +13,8 @@
 
 #ifdef LINUX
 #include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 
 #ifdef MACOSX
@@ -167,7 +169,7 @@
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(LINUX) // || defined(MACOSX)
+#elif defined(LINUX) && !defined(__FreeBSD__) // || defined(MACOSX)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
         long ap = sysconf(_SC_AVPHYS_PAGES);
