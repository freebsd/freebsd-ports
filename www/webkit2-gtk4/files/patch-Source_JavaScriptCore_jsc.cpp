--- Source/JavaScriptCore/jsc.cpp.orig	2021-09-22 23:05:58 UTC
+++ Source/JavaScriptCore/jsc.cpp
@@ -100,6 +100,9 @@
 #else
 #include <unistd.h>
 #endif
+#if PLATFORM(GTK)
+#include <locale.h>
+#endif
 
 #if PLATFORM(COCOA)
 #include <crt_externs.h>
