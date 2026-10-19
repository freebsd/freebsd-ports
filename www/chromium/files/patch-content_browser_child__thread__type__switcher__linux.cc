--- content/browser/child_thread_type_switcher_linux.cc.orig	2026-10-18 13:29:39 UTC
+++ content/browser/child_thread_type_switcher_linux.cc
@@ -9,6 +9,7 @@
 #include "base/containers/flat_map.h"
 #include "base/linux_util.h"
 #include "base/logging.h"
+#include "base/notimplemented.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/process/process_handle.h"
 #include "base/sequence_checker.h"
@@ -41,6 +42,9 @@ class ChildThreadTypeSwitcher::LauncherThreadState {
 
   void SetThreadTypes(std::vector<mojom::ThreadTypeChangePtr> changes) {
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+#if BUILDFLAG(IS_BSD)
+    NOTIMPLEMENTED();
+#else
     bool refreshed = false;
     for (const auto& change : changes) {
       const pid_t ns_tid = change->platform_thread_id;
@@ -61,6 +65,7 @@ class ChildThreadTypeSwitcher::LauncherThreadState {
       }
       SetThreadType(base::PlatformThreadId(peer_tid), change->thread_type);
     }
+#endif
   }
 
  private:
@@ -97,6 +102,7 @@ class ChildThreadTypeSwitcher::LauncherThreadState {
 
   void SetThreadType(base::PlatformThreadId peer_tid,
                      base::ThreadType thread_type) {
+#if !BUILDFLAG(IS_BSD)
     if (peer_tid.raw() == peer_pid_ && !IsAllowedForMainThread(thread_type)) {
       // TODO(crbug.com/40226692): Consider reporting with ReceivedBadMessage().
       DLOG(WARNING) << "Changing main thread type to another value than "
@@ -104,6 +110,7 @@ class ChildThreadTypeSwitcher::LauncherThreadState {
       return;
     }
     base::PlatformThread::SetThreadType(peer_pid_, peer_tid, thread_type);
+#endif
   }
 
   const base::ProcessId peer_pid_;
