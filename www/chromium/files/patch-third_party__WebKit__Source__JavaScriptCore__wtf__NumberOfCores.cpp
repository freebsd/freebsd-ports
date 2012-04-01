--- third_party/WebKit/Source/JavaScriptCore/wtf/NumberOfCores.cpp.orig	2012-03-31 03:21:08.000000000 +0300
+++ third_party/WebKit/Source/JavaScriptCore/wtf/NumberOfCores.cpp	2012-03-31 03:21:30.000000000 +0300
@@ -27,6 +27,7 @@
 #include "NumberOfCores.h"
 
 #if OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
+#include <unistd.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #elif OS(LINUX) || OS(AIX) || OS(SOLARIS)
