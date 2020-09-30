--- Source/JavaScriptCore/jsc.cpp.orig	2020-08-12 09:17:53 UTC
+++ Source/JavaScriptCore/jsc.cpp
@@ -94,6 +94,9 @@
 #else
 #include <unistd.h>
 #endif
+#if PLATFORM(GTK)
+#include <locale.h>
+#endif
 
 #if PLATFORM(COCOA)
 #include <crt_externs.h>
