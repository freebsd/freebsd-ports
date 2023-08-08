https://bugs.webkit.org/show_bug.cgi?id=129963

Index: Source/WTF/wtf/PlatformEnable.h
--- Source/WTF/wtf/PlatformEnable.h.orig
+++ Source/WTF/wtf/PlatformEnable.h
@@ -646,7 +646,7 @@
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 
 /* Enable the DFG JIT on X86 and X86_64. */
-#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HURD) || OS(WINDOWS))
+#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 
