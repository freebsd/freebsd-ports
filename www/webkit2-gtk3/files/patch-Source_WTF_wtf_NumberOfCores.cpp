--- Source/WTF/wtf/NumberOfCores.cpp.orig	2017-04-11 20:08:02.949675000 +0200
+++ Source/WTF/wtf/NumberOfCores.cpp	2017-04-11 20:08:43.723709000 +0200
@@ -33,6 +33,7 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(SOLARIS) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
+#include <stdio.h> // sscanf()
 #include <unistd.h>
 #elif OS(WINDOWS)
 #include <windows.h>
