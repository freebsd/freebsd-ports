--- src/c/lm/main/Main.cpp.orig	2018-09-09 19:24:07 UTC
+++ src/c/lm/main/Main.cpp
@@ -49,6 +49,9 @@
 #include <sys/stat.h>
 #if defined(MACOSX)
 #include <sys/sysctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(LINUX)
 #include <sys/sysinfo.h>
 #endif
@@ -110,6 +113,11 @@ int getPhysicalCpuCores()
     size_t  physicalCpuCoresSize=sizeof(physicalCpuCores);
     sysctlbyname("hw.activecpu",&physicalCpuCores,&physicalCpuCoresSize,NULL,0);
     return physicalCpuCores;
+    #elif defined(__FreeBSD__)
+    int	np = 0;
+    size_t	len = sizeof(np);
+    sysctlbyname("hw.ncpu",&np,&len,NULL,0);
+    return np;
     #elif defined(LINUX)
 	#ifdef ARM
 	return get_nprocs_conf();
