--- third_party/swiftshader/src/Vulkan/VkDebug.cpp.orig	2020-03-05 18:26:16 UTC
+++ third_party/swiftshader/src/Vulkan/VkDebug.cpp
@@ -22,6 +22,11 @@
 #define PTRACE
 #include <sys/types.h>
 #include <sys/ptrace.h>
+# if defined(__FreeBSD__)
+# include <sys/sysctl.h>
+# include <sys/user.h>
+# include <unistd.h>
+# endif
 #elif defined(_WIN32) || defined(_WIN64)
 #include <windows.h>
 #elif defined(__APPLE__) || defined(__MACH__)
@@ -33,7 +38,7 @@ namespace {
 
 bool IsUnderDebugger()
 {
-#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)
+#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__) && !defined(__FreeBSD__)
 	static bool checked = false;
 	static bool res = false;
 
@@ -55,7 +60,7 @@ bool IsUnderDebugger()
 	return res;
 #elif defined(_WIN32) || defined(_WIN64)
 	return IsDebuggerPresent() != 0;
-#elif defined(__APPLE__) || defined(__MACH__)
+#elif defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
 	// Code comes from the Apple Technical Q&A QA1361
 
 	// Tell sysctl what info we're requestion. Specifically we're asking for
@@ -70,14 +75,22 @@ bool IsUnderDebugger()
 	struct kinfo_proc info;
 	size_t size = sizeof(info);
 
+# if defined(__FreeBSD__)
+	info.ki_flag = 0;
+# else
 	info.kp_proc.p_flag = 0;
+# endif
 
 	// Get the info we're requesting, if sysctl fails then info.kp_proc.p_flag will remain 0.
 	res = sysctl(request, sizeof(request) / sizeof(*request), &info, &size, NULL, 0);
 	ASSERT_MSG(res == 0, "syscl returned %d", res);
 
 	// We're being debugged if the P_TRACED flag is set
+# if defined(__FreeBSD__)
+	return ((info.ki_flag & P_TRACED) != 0);
+# else
 	return ((info.kp_proc.p_flag & P_TRACED) != 0);
+# endif
 #else
 	return false;
 #endif
