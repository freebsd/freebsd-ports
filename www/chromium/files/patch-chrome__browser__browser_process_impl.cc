--- chrome/browser/browser_process_impl.cc.orig	2013-09-25 23:32:28.000000000 +0300
+++ chrome/browser/browser_process_impl.cc	2013-09-25 23:34:24.000000000 +0300
@@ -244,7 +244,7 @@
 
   ExtensionRendererState::GetInstance()->Shutdown();
 
-#if !defined(OS_ANDROID) && !defined(OS_IOS)
+#if !defined(OS_ANDROID) && !defined(OS_IOS) && !defined(OS_BSD)
   media_file_system_registry_.reset();
   // Delete |storage_monitor_| now. Otherwise the FILE thread would be gone
   // when we try to release it in the dtor and Valgrind would report a
@@ -618,7 +618,7 @@
 }
 
 chrome::StorageMonitor* BrowserProcessImpl::storage_monitor() {
-#if defined(OS_ANDROID) || defined(OS_IOS)
+#if defined(OS_ANDROID) || defined(OS_IOS) || defined(OS_BSD)
   return NULL;
 #else
   return storage_monitor_.get();
@@ -627,7 +627,7 @@
 
 void BrowserProcessImpl::set_storage_monitor_for_test(
     scoped_ptr<chrome::StorageMonitor> monitor) {
-#if !defined(OS_ANDROID) && !defined(OS_IOS)
+#if !defined(OS_ANDROID) && !defined(OS_IOS) && !defined(OS_BSD)
   storage_monitor_ = monitor.Pass();
 #endif
 }
@@ -923,7 +923,7 @@
   }
 #endif
 
-#if !defined(OS_ANDROID) && !defined(OS_IOS)
+#if !defined(OS_ANDROID) && !defined(OS_IOS) && !defined(OS_BSD)
   storage_monitor_.reset(chrome::StorageMonitor::Create());
 #endif
 
