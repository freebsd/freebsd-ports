--- src/3rdparty/webkit/JavaScriptCore/jit/JITStubs.cpp.orig	2010-11-06 02:55:20.000000000 +0100
+++ src/3rdparty/webkit/JavaScriptCore/jit/JITStubs.cpp	2011-01-17 14:32:18.000000000 +0100
@@ -77,7 +77,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if OS(LINUX) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #else
 #define SYMBOL_STRING_RELOCATION(name) SYMBOL_STRING(name)
