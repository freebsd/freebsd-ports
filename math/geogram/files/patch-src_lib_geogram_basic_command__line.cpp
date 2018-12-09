--- src/lib/geogram/basic/command_line.cpp.orig	2018-12-09 17:46:56 UTC
+++ src/lib/geogram/basic/command_line.cpp
@@ -54,7 +54,7 @@
 #include <iostream>
 #include <iomanip>
 
-#if defined(GEO_OS_LINUX) || defined(GEO_OS_APPLE)
+#if defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD) || defined(GEO_OS_APPLE)
 #include <sys/ioctl.h>
 #include <stdio.h>
 #include <unistd.h>
