--- ./src/log/SBlogOSUtils.cpp.orig	Fri Dec 29 10:50:07 2006
+++ ./src/log/SBlogOSUtils.cpp	Fri Dec 29 10:50:26 2006
@@ -37,6 +37,7 @@
 #include <sys/times.h>                  // For times( )
 #endif
 
+#include <sys/types.h>
 #include <sys/timeb.h>                  // for ftime( )/_ftime( )
 #include <sys/stat.h>                   // for stat( )
 
