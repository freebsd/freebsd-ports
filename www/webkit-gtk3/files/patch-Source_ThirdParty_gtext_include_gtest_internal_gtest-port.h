--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2013-06-10 07:06:02.000000000 +0000
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h	2013-06-10 07:51:20.000000000 +0000
@@ -172,6 +172,7 @@
 #include <stddef.h>  // For ptrdiff_t
 #include <stdlib.h>
 #include <stdio.h>
+#include <unistd.h>
 #include <string.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
