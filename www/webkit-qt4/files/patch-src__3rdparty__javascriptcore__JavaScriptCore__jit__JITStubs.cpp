--- ./src/3rdparty/javascriptcore/JavaScriptCore/jit/JITStubs.cpp.orig	2011-12-08 06:06:02.000000000 +0100
+++ ./src/3rdparty/javascriptcore/JavaScriptCore/jit/JITStubs.cpp	2012-01-08 17:18:52.511348683 +0100
@@ -80,7 +80,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if OS(LINUX) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #else
 #define SYMBOL_STRING_RELOCATION(name) SYMBOL_STRING(name)
