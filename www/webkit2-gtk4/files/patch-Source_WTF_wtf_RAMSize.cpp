--- Source/WTF/wtf/RAMSize.cpp.orig	2023-01-31 18:03:55.638729000 -0800
+++ Source/WTF/wtf/RAMSize.cpp	2023-01-31 18:04:10.292282000 -0800
@@ -31,7 +31,7 @@
 #if OS(WINDOWS)
 #include <windows.h>
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
 #include <sys/sysinfo.h>
 #elif OS(UNIX)
 #include <unistd.h>
@@ -56,7 +56,7 @@
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
