--- src/bitmsghash/bitmsghash.cpp.orig	2016-05-02 19:51:46 UTC
+++ src/bitmsghash/bitmsghash.cpp
@@ -11,7 +11,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__DragonFly__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -89,6 +89,8 @@ void getnumthreads()
 #else
 	if (sysctlbyname("hw.logicalcpu", &core_count, &len, 0, 0) == 0)
 		numthreads = core_count;
+	else if (sysctlbyname("hw.ncpu", &core_count, &len, 0, 0) == 0)
+		numthreads = core_count;
 #endif
 	for (unsigned int i = 0; i < len * 8; i++)
 #if defined(_WIN32)
