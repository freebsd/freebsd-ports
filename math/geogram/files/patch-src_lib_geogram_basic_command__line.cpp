--- src/lib/geogram/basic/command_line.cpp.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/basic/command_line.cpp
@@ -49,7 +49,7 @@
 #include <iostream>
 #include <iomanip>
 
-#if defined(GEO_OS_LINUX) || defined(GEO_OS_APPLE)
+#if defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD) || defined(GEO_OS_APPLE)
 #include <sys/ioctl.h>
 #include <stdio.h>
 #include <unistd.h>
