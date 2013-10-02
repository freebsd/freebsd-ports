--- src/3rdparty/qtsolutions/qtlocalpeer.cpp.orig	2009-06-03 11:32:52.000000000 +0000
+++ src/3rdparty/qtsolutions/qtlocalpeer.cpp
@@ -56,6 +56,7 @@ typedef BOOL(WINAPI*PProcessIdToSessionI
 static PProcessIdToSessionId pProcessIdToSessionId = 0;
 #endif
 #if defined(Q_OS_UNIX)
+#include <unistd.h>
 #include <time.h>
 #endif
 
