$OpenBSD: patch-Source_JavaScriptCore_jit_ExecutableAllocator_h,v 1.1 2013/04/13 09:11:02 landry Exp $

https://bugs.webkit.org/show_bug.cgi?id=61137

--- Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2016-02-04 11:16:16 UTC
+++ Source/JavaScriptCore/jit/ExecutableAllocator.h
@@ -78,7 +78,7 @@ class DemandExecutableAllocator;
 static const size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
 #elif CPU(ARM64)
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 static const size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
