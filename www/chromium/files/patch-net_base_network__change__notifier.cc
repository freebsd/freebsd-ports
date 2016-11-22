--- net/base/network_change_notifier.cc.orig	2016-10-06 04:02:22.000000000 +0300
+++ net/base/network_change_notifier.cc	2016-10-14 20:28:12.376281000 +0300
@@ -533,7 +533,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
@@ -753,7 +752,7 @@
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -978,7 +977,7 @@
   network_change_calculator_->Init();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
