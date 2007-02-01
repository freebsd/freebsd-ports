--- ./src/inet/SBinetHttpStream.cpp.orig	Fri Dec 29 10:58:52 2006
+++ ./src/inet/SBinetHttpStream.cpp	Fri Dec 29 10:59:06 2006
@@ -35,6 +35,7 @@
 #include <windows.h>
 #endif
 
+#include <sys/types.h>
 #include <sys/timeb.h>                  // for _ftime( )/ftime( )
 #include <assert.h>
 
