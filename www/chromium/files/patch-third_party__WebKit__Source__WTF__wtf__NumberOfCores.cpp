--- third_party/WebKit/Source/WTF/wtf/NumberOfCores.cpp.orig	2012-04-25 10:06:07.000000000 +0300
+++ third_party/WebKit/Source/WTF/wtf/NumberOfCores.cpp	2012-04-29 21:45:39.000000000 +0300
@@ -29,6 +29,7 @@
 #if OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
 // sys/types.h must come before sys/sysctl.h because the latter uses
 // data types defined in the former. See sysctl(3) and style(9).
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(SOLARIS)
