commit 27caf07f31eaa5f69158e90ee17905f86ad492d5
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>
Date:   Sun Dec 8 18:40:28 2024 +0100

    Bug 1935899 - Extend BSD about:processes for FreeBSD r=florian,gaston
    
    The sysctl interface on FreeBSD is ever so slightly different
    from OpenBSD. Especially, we have a different number of elements
    in the mib name, so namelen becomes a variable initialised inside
    the #ifdef'ed code, and the calculation of the number of processes
    in the result differs between OpenBSD and FreeBSD. Lastly, we need
    to process the results differently on FreeBSD.

diff --git toolkit/components/processtools/ProcInfo_bsd.cpp toolkit/components/processtools/ProcInfo_bsd.cpp
index a6ff4881940c..87ccad7e9467 100644
--- toolkit/components/processtools/ProcInfo_bsd.cpp
+++ toolkit/components/processtools/ProcInfo_bsd.cpp
@@ -18,6 +18,9 @@
 #include <cstdio>
 #include <cstring>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/user.h>
+#endif
 
 namespace mozilla {
 
@@ -50,25 +53,39 @@ ProcInfoPromise::ResolveOrRejectValue GetProcInfoSync(
   }
   for (const auto& request : aRequests) {
     size_t size;
-    int mib[6];
+#ifdef __FreeBSD__
+    constexpr int mibsize = 4;
+    int mib[mibsize];
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PID | KERN_PROC_INC_THREAD;
+    mib[3] = request.pid;
+#else
+    constexprint mibsize = 6;
+    int mib[mibsize];
     mib[0] = CTL_KERN;
     mib[1] = KERN_PROC;
     mib[2] = KERN_PROC_PID | KERN_PROC_SHOW_THREADS;
     mib[3] = request.pid;
     mib[4] = sizeof(kinfo_proc);
     mib[5] = 0;
-    if (sysctl(mib, 6, nullptr, &size, nullptr, 0) == -1) {
+#endif
+    if (sysctl(mib, mibsize, nullptr, &size, nullptr, 0) == -1) {
       // Can't get info for this process. Skip it.
       continue;
     }
 
+#ifdef __FreeBSD__
+    auto procs = MakeUniqueFallible<kinfo_proc[]>(size / sizeof(kinfo_proc));
+#else
     mib[5] = size / sizeof(kinfo_proc);
     auto procs = MakeUniqueFallible<kinfo_proc[]>(mib[5]);
+#endif
     if (!procs) {
       result.SetReject(NS_ERROR_OUT_OF_MEMORY);
       return result;
     }
-    if (sysctl(mib, 6, procs.get(), &size, nullptr, 0) == -1 &&
+    if (sysctl(mib, mibsize, procs.get(), &size, nullptr, 0) == -1 &&
         errno != ENOMEM) {
       continue;
     }
@@ -84,19 +101,34 @@ ProcInfoPromise::ResolveOrRejectValue GetProcInfoSync(
     bool found = false;
     for (size_t i = 0; i < size / sizeof(kinfo_proc); i++) {
       const auto& p = procs[i];
+#ifdef __FreeBSD__
+      if (i == 0) {
+#else
       if (p.p_tid == -1) {
+#endif
         // This is the process.
         found = true;
+#ifdef __FreeBSD__
+        info.cpuTime = uint64_t(p.ki_runtime) * 1'000u;
+        info.memory = (p.ki_tsize + p.ki_dsize + p.ki_ssize) * getpagesize();
+#else
         info.cpuTime = uint64_t(p.p_rtime_sec) * 1'000'000'000u +
                        uint64_t(p.p_rtime_usec) * 1'000u;
         info.memory =
             (p.p_vm_tsize + p.p_vm_dsize + p.p_vm_ssize) * getpagesize();
+#endif
+
       } else {
         // This is one of its threads.
         ThreadInfo threadInfo;
+#ifdef __FreeBSD__
+        threadInfo.tid = p.ki_tid;
+        threadInfo.cpuTime = uint64_t(p.ki_runtime) * 1'000u;
+#else
         threadInfo.tid = p.p_tid;
         threadInfo.cpuTime = uint64_t(p.p_rtime_sec) * 1'000'000'000u +
                              uint64_t(p.p_rtime_usec) * 1'000u;
+#endif
         info.threads.AppendElement(threadInfo);
       }
     }
diff --git toolkit/components/processtools/moz.build toolkit/components/processtools/moz.build
index ee9d07cd6dec..d5c0aca9de14 100644
--- toolkit/components/processtools/moz.build
+++ toolkit/components/processtools/moz.build
@@ -39,7 +39,7 @@ BROWSER_CHROME_MANIFESTS += ["tests/browser/browser.toml"]
 # Platform-specific implementations of `ProcInfo`.
 toolkit = CONFIG["MOZ_WIDGET_TOOLKIT"]
 if toolkit == "gtk" or toolkit == "android":
-    if CONFIG["OS_TARGET"] == "OpenBSD":
+    if CONFIG["OS_TARGET"] in ("FreeBSD", "OpenBSD"):
         UNIFIED_SOURCES += ["ProcInfo_bsd.cpp"]
     elif CONFIG["OS_TARGET"] == "SunOS":
         UNIFIED_SOURCES += ["ProcInfo_solaris.cpp"]
