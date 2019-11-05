--- content/browser/scheduler/responsiveness/watcher.cc.orig	2019-09-16 09:41:14 UTC
+++ content/browser/scheduler/responsiveness/watcher.cc
@@ -96,7 +96,7 @@ void Watcher::DidRunTask(const base::PendingTask* task
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX) && defined(USE_OZONE)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     return currently_running_metadata_ui_.clear();
 #endif
     DCHECK_LE(*mismatched_task_identifiers, 1);
@@ -156,7 +156,7 @@ void Watcher::DidRunEventOnUIThread(const void* opaque
     mismatched_event_identifiers_ui_ += 1;
     // See comment in DidRunTask() for why |currently_running_metadata_ui_| may
     // be reset.
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX) && defined(USE_OZONE)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     return currently_running_metadata_ui_.clear();
 #endif
     DCHECK_LE(mismatched_event_identifiers_ui_, 1);
