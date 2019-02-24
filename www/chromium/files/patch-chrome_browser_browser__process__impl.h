--- chrome/browser/browser_process_impl.h.orig	2019-02-12 16:33:04.676012000 +0100
+++ chrome/browser/browser_process_impl.h	2019-02-12 16:33:35.429453000 +0100
@@ -367,7 +367,7 @@
   std::unique_ptr<ChromeResourceDispatcherHostDelegate>
       resource_dispatcher_host_delegate_;
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
@@ -376,7 +376,7 @@
   bool IsRunningInBackground() const;
   void OnPendingRestartResult(bool is_update_pending_restart);
   void RestartBackgroundInstance();
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
   // component updater is normally not used under ChromeOS due
   // to concerns over integrity of data shared between profiles,
