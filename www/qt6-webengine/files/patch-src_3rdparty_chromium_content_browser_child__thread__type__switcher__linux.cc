--- src/3rdparty/chromium/content/browser/child_thread_type_switcher_linux.cc.orig	2023-12-10 06:10:27 UTC
+++ src/3rdparty/chromium/content/browser/child_thread_type_switcher_linux.cc
@@ -20,6 +20,9 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
                                    base::ThreadType thread_type) {
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
 
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   bool ns_pid_supported = false;
   pid_t peer_tid = base::FindThreadID(peer_pid, ns_tid, &ns_pid_supported);
   if (peer_tid == -1) {
@@ -37,6 +40,7 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
 
   base::PlatformThread::SetThreadType(peer_pid, peer_tid, thread_type,
                                       base::IsViaIPC(true));
+#endif
 }
 
 }  // namespace
