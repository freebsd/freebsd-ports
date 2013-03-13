--- Source/JavaScriptCore/wtf/NumberOfCores.cpp.orig	2012-05-16 10:42:39.000000000 +0200
+++ Source/JavaScriptCore/wtf/NumberOfCores.cpp	2012-05-16 10:43:06.000000000 +0200
@@ -27,8 +27,8 @@
 #include "NumberOfCores.h"
 
 #if OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(SOLARIS)
 #include <unistd.h>
 #elif OS(WINDOWS)
