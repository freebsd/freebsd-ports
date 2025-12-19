--- src/3rdparty/chromium/third_party/swiftshader/src/Reactor/Debug.cpp.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/swiftshader/src/Reactor/Debug.cpp
@@ -46,7 +46,7 @@ bool IsUnderDebugger()
 
 bool IsUnderDebugger()
 {
-#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)
+#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 	static bool checked = false;
 	static bool res = false;
 
