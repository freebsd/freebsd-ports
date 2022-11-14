--- core/UnicodeConverter/UnicodeConverter.cpp.orig	2022-09-27 13:24:04 UTC
+++ core/UnicodeConverter/UnicodeConverter.cpp
@@ -38,6 +38,7 @@
 #include "unicode/usprep.h"
 
 //#include "../DesktopEditor/common/File.h"
+#define TRUE 1
 
 #if !defined (_WIN32) && !defined (_WIN64)
 #if defined (_LINUX) && !defined(__ANDROID__) && !defined(_IOS) && !defined(_MAC)
