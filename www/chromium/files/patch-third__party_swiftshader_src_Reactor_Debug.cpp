--- third_party/swiftshader/src/Reactor/Debug.cpp.orig	2020-05-18 15:27:49 UTC
+++ third_party/swiftshader/src/Reactor/Debug.cpp
@@ -23,16 +23,20 @@
 #	include <android/log.h>
 #endif
 
-#if defined(__unix__)
+#if defined(__unix__) && !defined(__FreeBSD__)
 #	define PTRACE
 #	include <sys/ptrace.h>
 #	include <sys/types.h>
 #elif defined(_WIN32) || defined(_WIN64)
 #	include <windows.h>
-#elif defined(__APPLE__) || defined(__MACH__)
+#elif defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
+#	include <sys/types.h>
 #	include <sys/sysctl.h>
 #	include <unistd.h>
 #endif
+#if defined(__FreeBSD__)
+#	include <sys/user.h>
+#endif
 
 #ifdef ERROR
 #	undef ERROR  // b/127920555
@@ -68,29 +72,48 @@ bool IsUnderDebugger()
 	return res;
 #elif defined(_WIN32) || defined(_WIN64)
 	return IsDebuggerPresent() != 0;
-#elif defined(__APPLE__) || defined(__MACH__)
+#elif defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
 	// Code comes from the Apple Technical Q&A QA1361
 
 	// Tell sysctl what info we're requestion. Specifically we're asking for
 	// info about this our PID.
 	int res = 0;
+#if defined(__FreeBSD__)
+	int request[6] = {
+		CTL_KERN,
+		KERN_PROC,
+		KERN_PROC_PID,
+		getpid(),
+		sizeof(struct kinfo_proc),
+		0
+	};
+#else
 	int request[4] = {
 		CTL_KERN,
 		KERN_PROC,
 		KERN_PROC_PID,
 		getpid()
 	};
+#endif
 	struct kinfo_proc info;
 	size_t size = sizeof(info);
 
+#if defined(__FreeBSD__)
+	info.ki_flag = 0;
+#else
 	info.kp_proc.p_flag = 0;
+#endif
 
 	// Get the info we're requesting, if sysctl fails then info.kp_proc.p_flag will remain 0.
 	res = sysctl(request, sizeof(request) / sizeof(*request), &info, &size, NULL, 0);
 	ASSERT_MSG(res == 0, "syscl returned %d", res);
 
 	// We're being debugged if the P_TRACED flag is set
+#if defined(__FreeBSD__)
+	return ((info.ki_flag & P_TRACED) != 0);
+#else
 	return ((info.kp_proc.p_flag & P_TRACED) != 0);
+#endif
 #else
 	return false;
 #endif
