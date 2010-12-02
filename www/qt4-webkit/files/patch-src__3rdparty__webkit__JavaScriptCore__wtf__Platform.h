--- ./src/3rdparty/webkit/JavaScriptCore/wtf/Platform.h.orig	2010-09-10 09:05:22.000000000 +0000
+++ ./src/3rdparty/webkit/JavaScriptCore/wtf/Platform.h	2010-11-04 11:29:10.000000000 +0000
@@ -937,6 +937,11 @@
     #define ENABLE_JIT 1
 #elif CPU(ARM_TRADITIONAL) && OS(LINUX)
     #define ENABLE_JIT 1
+#elif CPU(X86) && OS(FREEBSD) && GCC_VERSION >= 40100
+    #define ENABLE_JIT 1
+    #define WTF_USE_JIT_STUB_ARGUMENT_VA_LIST 1
+#elif CPU(X86_64) && OS(FREEBSD) && GCC_VERSION >= 40100
+    #define ENABLE_JIT 1
 #endif
 #endif /* PLATFORM(QT) */
 
@@ -1007,6 +1012,8 @@
     || (CPU(X86_64) && OS(LINUX) && GCC_VERSION >= 40100) \
     || (CPU(ARM_TRADITIONAL) && OS(LINUX)) \
     || (CPU(MIPS) && OS(LINUX)) \
+    || (CPU(X86) && OS(FREEBSD) && GCC_VERSION >= 40100) \
+    || (CPU(X86_64) && OS(FREEBSD) && GCC_VERSION >= 40100) \
     || (CPU(X86) && OS(DARWIN)) \
     || (CPU(X86_64) && OS(DARWIN))
 #define ENABLE_YARR 1
