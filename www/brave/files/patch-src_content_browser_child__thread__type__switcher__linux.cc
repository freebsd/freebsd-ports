--- src/content/browser/child_thread_type_switcher_linux.cc.orig	2026-10-20 12:00:32 UTC
+++ src/content/browser/child_thread_type_switcher_linux.cc
@@ -9,6 +9,7 @@
 #include "base/containers/flat_map.h"
 #include "base/linux_util.h"
 #include "base/logging.h"
+#include "base/notimplemented.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/process/process_handle.h"
 #include "base/sequence_checker.h"
@@ -41,6 +42,10 @@ class ChildThreadTypeSwitcher::LauncherT
 
   void SetThreadTypes(std::vector<mojom::ThreadTypeChangePtr> changes) {
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+#if BUILDFLAG(IS_BSD)
+    // There is no /proc/<pid>/task to translate the child's thread ids with.
+    NOTIMPLEMENTED();
+#else
     bool refreshed = false;
     for (const auto& change : changes) {
       const pid_t ns_tid = change->platform_thread_id;
@@ -61,6 +66,7 @@ class ChildThreadTypeSwitcher::LauncherT
       }
       SetThreadType(base::PlatformThreadId(peer_tid), change->thread_type);
     }
+#endif
   }
 
  private:
@@ -103,7 +109,10 @@ class ChildThreadTypeSwitcher::LauncherT
                     << "kDefault, kInteractive or kPresentation isn't allowed";
       return;
     }
+#if !BUILDFLAG(IS_BSD)
+    // The cross-process overload exists on Linux and ChromeOS only.
     base::PlatformThread::SetThreadType(peer_pid_, peer_tid, thread_type);
+#endif
   }
 
   const base::ProcessId peer_pid_;
